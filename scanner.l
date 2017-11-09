DIGIT			[0-9]
LETTER			[a-zA-Z_]
STRING			L?\"(\\.|[^\\"])*\"
%{
#include "hermit.h"
#include "lex_tokens.h"
#include "y.tab.h"
%}
%option nounput yylineno

%%
"/*"			{ comment(); }
"//"[^\n]*		{ /* line comment */ }
[ \t\n\r]		{ /* ignore whitespace */ }
#[^#\n]*#?		{ /* ignore #include */ }
"auto"			{ return (AUTO); }
"break"			{ return (BREAK); }
"case"			{ return (CASE); }
"char"			{ yylval.string_val.val = strdup(yytext); yylval.string_val.lineno = yylineno; return (CHAR); }
"const"			{ return (CONST); }
"continue"		{ return (CONTINUE); }
"default"		{ return (DEFAULT); }
"do"			{ return (DO); }
"double"		{ return (DOUBLE); }
"else"			{ return (ELSE); }
"enum"			{ return (ENUM); }
"extern"		{ return (EXTERN); }
"float"			{ return (FLOAT); }
"for"			{ return (FOR); }
"goto"			{ return (GOTO); }
"if"			{ return (IF); }
"inline"		{ return (INLINE); }
"int"			{ yylval.string_val.val = strdup(yytext); yylval.string_val.lineno = yylineno; return (INT); }
"long"			{ return (LONG); }
"register"		{ return (REGISTER); }
"restrict"		{ return (RESTRICT); }
"return"		{ return (RETURN); }
"short"			{ return (SHORT); }
"signed"		{ return (SIGNED); }
"sizeof"		{ return (SIZEOF); }
"static"		{ return (STATIC); }
"struct"		{ return (STRUCT); }
"switch"		{ return (SWITCH); }
"typedef"		{ return (TYPEDEF); }
"union"			{ return (UNION); }
"unsigned"		{ return (UNSIGNED); }
"void"			{ yylval.string_val.val = strdup(yytext); yylval.string_val.lineno = yylineno; return (VOID); }
"volatile"		{ return (VOLATILE); }
"while"			{ return (WHILE); }
{DIGIT}+		{ yylval.integer_val.val = atoi(yytext); yylval.integer_val.lineno = yylineno; return (DIGIT); }
{LETTER}+		{ yylval.string_val.val = strdup(yytext); yylval.string_val.lineno = yylineno; return (IDENTIFIER); }
{STRING}		{ yylval.string_val.val = strdup(yytext); yylval.string_val.lineno = yylineno; return (STRING_LITERAL); }
"..."			{ return (ELLIPSIS); }
">>="			{ return (RIGHT_ASSIGN); }
"<<="			{ return (LEFT_ASSIGN); }
"+="			{ return (ADD_ASSIGN); }
"-="			{ return (SUB_ASSIGN); }
"*="			{ return (MUL_ASSIGN); }
"/="			{ return (DIV_ASSIGN); }
"%="			{ return (MOD_ASSIGN); }
"&="			{ return (AND_ASSIGN); }
"^="			{ return (XOR_ASSIGN); }
"|="			{ return (OR_ASSIGN); }
">>"			{ return (RIGHT_OP); }
"<<"			{ return (LEFT_OP); }
"++"			{ return (INC_OP); }
"--"			{ return (DEC_OP); }
"->"			{ return (PTR_OP); }
"&&"			{ return (AND_OP); }
"||"			{ return (OR_OP); }
"<="			{ return (LE_OP); }
">="			{ return (GE_OP); }
"=="			{ return (EQ_OP); }
"!="			{ return (NE_OP); }
";"				{ return (';'); }
("{"|"<%")		{ return ('{'); }
("}"|"%>")		{ return ('}'); }
","				{ return (','); }
":"				{ return (':'); }
"="				{ return ('='); }
"("				{ return ('('); }
")"				{ return (')'); }
("["|"<:")		{ return ('['); }
("]"|":>")		{ return (']'); }
"."				{ return ('.'); }
"&"				{ return ('&'); }
"!"				{ return ('!'); }
"~"				{ return ('~'); }
"-"				{ return ('-'); }
"+"				{ return ('+'); }
"*"				{ return ('*'); }
"/"				{ return ('/'); }
"%"				{ return ('%'); }
"<"				{ return ('<'); }
">"				{ return ('>'); }
"^"				{ return ('^'); }
"|"				{ return ('|'); }
"?"				{ return ('?'); }
.				{ fputs("Error", stderr); }
%%


/**
 * yywrap - todo
 * Return: todo
 */
int yywrap(void)
{
	return (1);
}

/**
 * comment - skips characters until closing comment is found
 */
void comment(void)
{
	char crnt, prev;

	for (prev = 0; (crnt = input()) != 0; prev = crnt)
	{
		if (crnt == '/' && prev == '*')
			return;
	}
	fputs("unterminated comment", stderr);
}

/**
 * yyerror - prints error message from lex
 * @str: error message
 */
void yyerror(const char *str)
{
	fprintf(stderr, "error on line: %d, %s\n", yylineno, str);
}
