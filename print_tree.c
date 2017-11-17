#include "hermit.h"
#include "print_tree.h"
#define INITIAL_INDENT_STEP 3

int indentstep = INITIAL_INDENT_STEP;

void print_indent(int indent, int lineno);
void print_function_decs(int indent, A_func_dec_list functions);
void print_expression(int indent, A_expression exp);
void print_func_dec(int indent, A_func_dec function);
void print_param_list(int indent, A_param_list params);
void print_param(int indent, A_param param);
void print_statement_list(int indent, A_statement_list statements);
void print_statement(int indent, A_statement statement);

/**
 * print_expression - prints an expression
*/
void print_expression(int indent, A_expression exp)
{
	switch(exp->type)
	{
		case OpExp:
		case VarExp:
		case CallExp:
			break;
		case IntExp:
			print_indent(indent, exp->lineno);
			printf("Integer Literal: %d\n", exp->self.int_exp.value);
			break;
	}
}

/**
 * print_statement - prints a statement
 */
void print_statement(int indent, A_statement statement)
{
	switch(statement->type)
	{
		case Assign:
		case VarDec:
		case Call:
			/*
			print_indent(indent, statement->lineno);
			puts("Assign:");
			print_indent(indent + 1, statement->self.assign_stm.lval->lineno);
			puts("LVAL:");
			print_variable(indent + 2, statement->self.assign_stm.lval);
			print_indent(indent + 1, statement->self.assign_stm.rval-lineno);
			puts("RVAL:");
			print_expression(indent + 2, statement->self.assign_stm.rval);*/
			break;
		case Block:
			print_indent(indent, statement->lineno);
			puts("{");
			print_statement_list(indent + 1, statement->self.block_stm.statements);
			print_indent(indent, statement->lineno);
			puts("}");
			break;
		case Return:
			print_indent(indent, statement->lineno);
			puts("Return");
			if (statement->self.return_stm.retval != NULL)
				print_expression(indent + 1, statement->self.return_stm.retval);
			else
			{
				print_indent(indent + 1, statement->lineno);
				printf("None");
			}
			break;
		case Empty:
			print_indent(indent, statement->lineno);
			puts("Empty");
			break;
	}
}

/**
 * print_statement_list - prints a statement list
 */
void print_statement_list(int indent, A_statement_list statements)
{
	if (!statements)
		return;
	print_statement(indent, statements->first);
	print_statement_list(indent, statements->next);
}

/**
 * print_param - prints parameter
 */
void print_param(int indent, A_param param)
{
	print_indent(indent, param->lineno);
	printf("%s %s", param->type, param->name);
	puts("");
}

/**
 * print_param_list - prints a parameter list
 */
void print_param_list(int indent, A_param_list params)
{
	if (!params)
		return;
	print_param(indent, params->first);
	print_param_list(indent, params->next);
}

/**
 * print_func_dec - prints a function declaration
*/
void print_func_dec(int indent, A_func_dec function)
{
	if (!function)
		return;
	if (function->type == Prototype)
	{
		print_indent(indent, function->lineno);
		printf("Prototype: %s\n", function->self.prototype.name);
		print_indent(indent + 1, function->lineno);
		puts("Parameters");
		print_param_list(indent + 2, function->self.prototype.params);
	}
	else if (function->type == Function)
	{
		print_indent(indent, function->lineno);
		printf("Function Definition: %s\n", function->self.function_def.name);
		print_indent(indent + 1, function->lineno);
		puts("Parameters");
		print_param_list(indent + 2, function->self.function_def.params);
		if (function->self.function_def.body != NULL)
		{
			print_indent(indent + 1, function->self.function_def.body->lineno);
			puts("Function Body");
			print_statement_list(indent + 2, function->self.function_def.body);
		}
		else
		{
			print_indent(indent + 1, function->lineno);
			puts("No Body");
		}
	}
	else
		printf("Error in function declaration at line: %d\n", function->lineno);
}

/**
 * print_indent - prints indent
 */
void print_indent(int indent, int lineno)
{
	int i;

	printf("%3d ", lineno);
	for (i = 0; i < indent * indentstep; i++)
		printf(" ");
	fflush(stdout);
}

/**
 * print_function_decs - prints a function declaration list
 */
void print_function_decs(int indent, A_func_dec_list functions)
{
	if (!functions)
		return;
	print_func_dec(indent, functions->first);
	print_function_decs(indent, functions->next);
}

/**
 * print_tree - entrty point for printing program
 */
void print_tree(A_program program)
{
	print_function_decs(0, program->function_decs);
}

/**
 * set_indent - sets the indent size
 */
void set_indent(int new_indent)
{
	indentstep = new_indent;
}
