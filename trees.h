#ifndef TREES_H
#define TREES_H

typedef enum {ADD, SUB, MUL, DIV} A_operator;

typedef struct A_program_t			*A_program;
typedef struct A_var_dec_t			*A_var_dec;
typedef struct A_var_dec_list_t		*A_var_dec_list;
typedef struct A_func_dec_t			*A_func_dec;
typedef struct A_func_dec_list_t	*A_func_dec_list;
typedef struct A_param_t			*A_param;
typedef struct A_param_list_t		*A_param_list;
typedef struct A_statement_t		*A_statement;
typedef struct A_statement_list_t	*A_statement_list;
typedef struct A_expression_t 		*A_expression;
typedef struct A_expression_list_t	*A_expression_list;
typedef struct A_variable_t 		*A_variable;

A_program program(int lineno, A_func_dec_list func_decs);
A_var_dec variable_dec(int lineno, char *type, char *name, int array);
A_var_dec_list variable_dec_list(int lineno, A_var_dec first, A_var_dec_list next);
A_func_dec function_def(int lineno, char *return_type, char *name, A_param_list params, A_statement_list body);
A_func_dec_list function_dec_list(int lineno, A_func_dec first, A_func_dec_list next);
A_func_dec prototype(int lineno, char *return_type, char *name, A_param_list params);
A_param parameter(int lineno, char *type, char *name, int array);
A_param_list parameter_list(int lineno, A_param first, A_param_list next);

A_statement assign_statement(int lineno, A_variable lval, A_expression rval);
A_statement var_dec_statement(int lineno, char *type, char *name, int array, A_expression init);
A_statement call_statement(int lineno, char *name, A_expression_list actuals);
A_statement block_statement(int lineno, A_statement_list statements);
A_statement return_statement(int lineno, A_expression retval);
A_statement empty_statement(int lineno);
A_statement_list statement_list(int lineno, A_statement first, A_statement_list next);

A_expression int_expression(int lineno, int value);
A_expression op_expression(int lineno, A_operator op, A_expression lval, A_expression rval);
A_expression var_expression(int lineno, A_variable var);
A_expression call_expression(int lineno, char *name, A_expression_list actuals);
A_expression_list expression_list(int lineno, A_expression first, A_expression_list next);


/**
 *
 */
struct A_program_t {
	int lineno;
	A_func_dec_list function_decs;
};

/**
 * var_dec_t -  defines a variable declaration
 * @lineno: line number of instruction
 * @type: variable type
 * @array: todo
 */
struct A_var_dec_t {
	int lineno;
	char *type;
	char *name;
	int array;
};

/**
 *
 *
 */
struct A_var_dec_list_t {
	int lineno;
	A_var_dec first;
	A_var_dec_list next;
};

/**
 * func_dec_t - defines a function declaration
 * @lineno: position of instruction
 */
struct A_func_dec_t {
	int lineno;
	enum {Prototype, Function} type;
	union {
		struct {
			char *return_type;
			char *name;
			A_param_list params;
		} prototype;
		struct {
			char *return_type;
			char *name;
			A_param_list params;
			A_statement_list body;
		} function_def;
	} self;
};

/**
 *
 *
 */
struct A_func_dec_list_t {
	int lineno;
	A_func_dec first;
	A_func_dec_list next;
};

/**
 *
 *
 */
struct A_param_t {
	int lineno;
	char *type;
	char *name;
	int array;
};

/**
 *
 *
 */
struct A_param_list_t {
	int lineno;
	A_param first;
	A_param_list next;
};

/**
 *
 *
 */
struct A_statement_t {
	int lineno;
	enum {Assign, VarDec, Block, Call, Return, Empty} type;
	union {
		struct {
			A_variable lval;
			A_expression rval;
		} assign_stm;
		struct {
			char *name;
			char *type;
			int array;
			A_expression init;
		} var_dec_stm;
		struct {
			A_statement_list statements;
		} block_stm;
		struct {
			char *name;
			A_expression_list actuals;
		} call_stm;
		struct {
			A_expression retval;
		} return_stm;
	} self;
};

/**
 *
 *
 *
 */
struct A_statement_list_t {
	int lineno;
	A_statement first;
	A_statement_list next;
};

/**
 *
 *
 */
struct A_expression_t {
	int lineno;
	enum {IntExp, OpExp, VarExp, CallExp} type;
	union {
		struct {
			int value;
		} int_exp;
		struct {
			A_operator op;
			A_expression lval;
			A_expression rval;
		} op_exp;
		struct {
			A_variable var;
		} var_exp;
		struct {
			char *name;
			A_expression_list actuals;
		} call_exp;
	} self;
};

/**
 *
 *
 */
struct A_expression_list_t {
	int lineno;
	A_expression first;
	A_expression_list next;
};

/**
 *
 *
 */
struct A_variable_t {
	int lineno;
	enum {BaseVar, ArrayVar} type;
	union {
		struct {
			char *name;
		} base_var;
		struct {
			A_variable base;
			A_expression index;
		} array_var;
	} self;
};

extern A_program A_root;

#endif
