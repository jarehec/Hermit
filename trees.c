#include "trees.h"
#include "util.h"

/**
 * program - creates a program and initializes the node
 */
A_program program(int lineno, A_func_dec_list func_decs)
{
	A_program retval = malloc_checked(sizeof(struct A_program_t));

	retval->lineno = lineno;
	retval->function_decs = func_decs;
	return (retval);
}

/**
 * variable_dec - creates a variable declaration node
 */
A_var_dec variable_dec(int lineno, char *type, char *name, int array)
{
	A_var_dec retval = malloc_checked(sizeof(struct A_var_dec_t));

	retval->lineno = lineno;
	retval->type = type;
	retval->name = name;
	retval->array = array;
	return (retval);
}

/**
 * variable_dec_list - creates a and initializes values for a variable declaration list
 */
A_var_dec_list variable_dec_list(int lineno, A_var_dec first, A_var_dec_list next)
{
	A_var_dec_list retval = malloc_checked(sizeof(struct A_var_dec_list_t));

	retval->lineno = lineno;
	retval->first = first;
	retval->next = next;
	return (retval);
}

/**
 * function_def - creates a node for function declarations
 */
A_func_dec function_def(int lineno, char *return_type, char *name, A_param_list params, A_statement_list body)
{
	A_func_dec retval = malloc_checked(sizeof(struct A_func_dec_t));

	retval->lineno = lineno;
	retval->type = Function;
	retval->self.function_def.return_type = return_type;
	retval->self.function_def.name = name;
	retval->self.function_def.params = params;
	retval->self.function_def.body = body;
	return (retval);
}

/**
 * prototype - creates a node for prototype declarations
 */
A_func_dec prototype(int lineno, char *return_type, char *name, A_param_list params)
{
	A_func_dec retval = malloc_checked(sizeof(struct A_func_dec_t));

	retval->lineno = lineno;
	retval->type = Prototype;
	retval->self.prototype.return_type = return_type;
	retval->self.prototype.name = name;
	retval->self.prototype.params = params;
	return (retval);
}

/**
 * function_dec_list - creates a node for function declaration lists
 */
A_func_dec_list function_dec_list(int lineno, A_func_dec first, A_func_dec_list next)
{
	A_func_dec_list retval = malloc_checked(sizeof(struct A_func_dec_list_t));

	retval->lineno = lineno;
	retval->first = first;
	retval->next = next;
	return (retval);
}

/**
 * parameter - creates a node for holding parameter information
 */
A_param parameter(int lineno, char *type, char *name, int array)
{
	A_param retval = malloc_checked(sizeof(struct A_param_t));

	retval->lineno = lineno;
	retval->type = type;
	retval->name = name;
	retval->array = array;
	return (retval);
}

/**
 * parameter_list - creates a node for a list of parameters
 */
A_param_list parameter_list(int lineno, A_param first, A_param_list next)
{
	A_param_list retval = malloc_checked(sizeof(struct A_param_list_t));

	retval->lineno = lineno;
	retval->first = first;
	retval->next = next;
	return (retval);
}

/**
 * assign_statement - creates an expression node for assignment statements
 */
A_statement assign_statement(int lineno, A_variable lval, A_expression rval)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = Assign;
	retval->self.assign_stm.lval = lval;
	retval->self.assign_stm.rval = rval;
	return (retval);
}

/**
 * var_dec_statement - node to hold information about variable declaration
 */
A_statement var_dec_statement(int lineno, char *type, char *name, int array, A_expression init)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = VarDec;
	retval->self.var_dec_stm.type = type;
	retval->self.var_dec_stm.name = name;
	retval->self.var_dec_stm.array = array;
	retval->self.var_dec_stm.init = init;
	return (retval);
}

/**
 * block_statement - creates a node for block statements
 */
A_statement block_statement(int lineno, A_statement_list statements)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = Block;
	retval->self.block_stm.statements = statements;
	return (retval);
}

/**
 * call_statement - creates a node for call statements
 */
A_statement call_statement(int lineno, char *name, A_expression_list actuals)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = Call;
	retval->self.call_stm.name = name;
	retval->self.call_stm.actuals = actuals;
	return (retval);
}

/**
 *
 *
 */
A_statement return_statement(int lineno, A_expression retvalue)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = Return;
	retval->self.return_stm.retval = retvalue;
	return (retval);
}

/**
 *
 *
 */
A_statement empty_statement(int lineno)
{
	A_statement retval = malloc_checked(sizeof(struct A_statement_t));

	retval->lineno = lineno;
	retval->type = Empty;
	return (retval);
}

/**
 *
 *
 */
A_statement_list statement_list(int lineno, A_statement first, A_statement_list next)
{
	A_statement_list retval = malloc_checked(sizeof(struct A_statement_list_t));

	retval->lineno = lineno;
	retval->first = first;
	retval->next = next;
	return (retval);
}

/**
 *
 *
 */
A_expression int_expression(int lineno, int value)
{
	A_expression retval = malloc_checked(sizeof(struct A_expression_t));

	retval->lineno = lineno;
	retval->type = IntExp;
	retval->self.int_exp.value = value;
	return (retval);
}

/**
 *
 *
 */
A_expression op_expression(int lineno, A_operator op, A_expression lval, A_expression rval)
{
	A_expression retval = malloc_checked(sizeof(struct A_expression_t));

	retval->lineno = lineno;
	retval->type = OpExp;
	retval->self.op_exp.op = op;
	retval->self.op_exp.lval = lval;
	retval->self.op_exp.rval = rval;
	return (retval);
}

/**
 *
 *
 */
A_expression var_expression(int lineno, A_variable var)
{
	A_expression retval = malloc_checked(sizeof(struct A_expression_t));

	retval->lineno = lineno;
	retval->type = VarExp;
	retval->self.var_exp.var = var;
	return (retval);
}

/**
 *
 *
 */
A_expression call_expression(int lineno, char *name, A_expression_list actuals)
{
	A_expression retval = malloc_checked(sizeof(struct A_expression_t));

	retval->lineno = lineno;
	retval->type = CallExp;
	retval->self.call_exp.name = name;
	retval->self.call_exp.actuals = actuals;
	return (retval);
}

/**
 *
 *
 *
 */
A_expression_list expression_list(int lineno, A_expression first, A_expression_list next)
{
	A_expression_list retval = malloc_checked(sizeof(struct A_expression_list_t));

	retval->lineno = lineno;
	retval->first = first;
	retval->next = next;
	return (retval);
}

A_program A_root;
