%{
#include "util.h"
#include "trees.h"
int yylex();
void yyerror(const char *s);
extern int yylineno;
A_program prog_root;

%}
%token SIZEOF
	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
	XOR_ASSIGN OR_ASSIGN

	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
	CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
	STRUCT UNION ENUM ELLIPSIS

	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start program

%union {
	struct {
		int val;
		int lineno;
	} integer_val;
	struct {
		char *val;
		int lineno;
	} string_val;
	int lineno;
	char *str;
	A_program program;
	A_variable var;
	A_param_list param_list;
	A_expression exp;
	A_func_dec func_dec;
	A_func_dec_list func_dec_list;
	A_statement_list stm_list;
	A_statement stm;
}
%token <integer_val> DIGIT
%token <string_val> IDENTIFIER INT CHAR VOID
%token <string_val> STRING_LITERAL
%type <str> type
%type <program> program
%type <param_list> params
%type <func_dec_list> function_list
%type <func_dec> function
%type <exp> value expression additive_expression multiplicative_expression
%type <stm_list> block_item_list block_statements
%type <stm> block_item assignment_statement return_statement statements declaration
%%

value
	: DIGIT { $$ = int_expression(1, $1.val); }
	;

type
	: INT { $$ = $1.val; }
	| CHAR { $$ = $1.val; }
	| VOID { $$ = $1.val; }
	;

multiplicative_expression
	: value
	| multiplicative_expression '*' value { }
	| multiplicative_expression '/' value { }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

expression
	: additive_expression
	;

assignment_statement
	: IDENTIFIER '=' expression ';' { /*$$ = assign_statement(1, $1, $3);*/ }
	;

declaration
	: type IDENTIFIER ';' { $$ = var_dec_statement($2.lineno, $1, $2.val, 1, NULL); }
	| type IDENTIFIER '=' expression ';' { $$ = var_dec_statement($2.lineno, $1, $2.val, 1, $4); }
	;

return_statement
	: RETURN ';' { $$ = return_statement(1, NULL); }
	| RETURN '(' value ')' ';' { $$ = return_statement(1, $3); }
	;

statements
	: assignment_statement { $$ = $1; }
	| return_statement { $$ = $1; }
	;

block_item
	: declaration { $$ = $1; }
	| statements { $$ = $1; }
	| expression { /*$$ = $1;*/ }
	;

block_item_list
	: block_item { $$ = statement_list(1, $1, NULL); }
	| block_item_list block_item { $$ = statement_list(1, $2, $1); }
	;

block_statements
	: '{' '}' { $$ = statement_list(1, empty_statement(1), NULL); }
	| '{' block_item_list '}' { $$ = $2; }
	;

params
	: type { $$ = parameter_list(1, parameter(1, $1, NULL, 1), NULL); }
	| type IDENTIFIER { $$ = parameter_list($2.lineno, parameter($2.lineno, $1, $2.val, 1), NULL); }
	| { $$ = parameter_list(1, parameter(1, NULL, NULL, 1), NULL); }
	;

function
	: type IDENTIFIER '(' params ')' block_statements { $$ = function_def($2.lineno, $1, $2.val, $4, $6); }
	;

function_list
	: function { $$ = function_dec_list(1, $1, NULL); }
	| function function_list { $$ = function_dec_list(1, $1, $2); }
	;

program
	: function_list { A_root = program(1, $1); }
	;
%%
