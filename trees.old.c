#include "util.h"
#include "symbol.h"
#include "trees.h"

/**
 *
 *
 */
A_var A_simple_var(int lineno, S_symbol sym)
{
	A_var retval = malloc_checked(sizeof(struct A_var_t));

	retval->lineno = lineno;
	retval->type = A_SimpleVar;
	retval->self.simple = sym;
	return (retval);
}

/**
 *
 *
 */
A_var A_field_var(int lineno, A_var var, S_symbol sym)
{
	A_var retval = malloc_checked(sizeof(struct A_var_t));

	retval->lineno = lineno;
	retval->type = A_FieldVar;
	retval->self.field.var = var;
	retval->self.field.sym = sym;
	return (retval);
}

/**
 *
 *
 */
A_var A_subscript_var(int lineno, A_var var, A_exp exp)
{
	A_var retval = malloc_checked(sizeof(struct A_var_t));

	retval->lineno = lineno;
	retval->type = A_SubscriptVar;
	retval->self.subscript.var = var;
	retval->self.subscript.exp = exp;
	return (retval);
}

/**
 *
 *
 */
A_exp A_var_exp(int lineno, A_var var)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_VarExp;
	retval->self.var = var;
	return (retval);
}

/**
 *
 */
A_exp A_null_exp(int lineno)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_NullExp;
	return (retval);
}

/**
 *
 */
A_exp A_int_exp(int lineno, int value)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_IntExp;
	retval->self.int_exp = value;
	return (retval);
}

/**
 *
 */
A_exp A_string_exp(int lineno, char *str)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_SimpleVar;
	retval->self.string_exp = str;
	return (retval);
}

/**
 *
 */
A_exp A_call_exp(int lineno, S_symbol func, A_exp_list args)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_CallExp;
	retval->self.call_exp.func = func;
	retval->self.call_exp.args = args;
	return (retval);
}

/**
 *
 */
A_exp A_op_exp(int lineno, A_operator oper, A_exp left, A_exp right)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_OpExp;
	retval->self.op.oper = oper;
	retval->self.op.left = left;
	retval->self.op.right = right;
	return (retval);
}

/**
 *
 */
A_exp A_record_exp(int lineno, S_symbol typ, A_efield_list fields)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_RecordExp;
	retval->self.record.typ = typ;
	retval->self.record.fields = fields;
	return (retval);
}

/**
 *
 */
A_exp A_assign_exp(int lineno, A_var var, A_exp exp)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_AssignExp;
	retval->self.assign.var = var;
	retval->self.assign.exp = exp;
	return (retval);
}

/**
 *
 */
A_exp A_func_exp(int lineno, A_dec_list decs, A_exp body)
{
	A_exp retval = malloc_checked(sizeof(struct A_exp_t));

	retval->lineno = lineno;
	retval->type = A_FuncExp;
	retval->self.function.decs = decs;
	retval->self.function.body = body;
	return (retval);
}

/**
 *
 */
A_dec A_func_Dec(int lineno, A_func_dec_list function)
{
	A_dec retval = malloc_checked(sizeof(struct A_dec_t));

	retval->lineno = lineno;
	retval->type = A_Func_Dec;
	retval->self.function = function;
	return (retval);
}

/**
 *
 */
A_dec A_var_Dec(int lineno, S_symbol var, S_symbol typ, A_exp init)
{
	A_dec retval = malloc_checked(sizeof(struct A_dec_t));

	retval->lineno = lineno;
	retval->type = A_Var_Dec;
	retval->self.var.var = var;
	retval->self.var.typ = typ;
	retval->self.var.init = init;
	retval->self.var.escape = TRUE;
	return (retval);
}

/**
 *
 */
A_dec A_type_Dec(int lineno, A_namety_list typ)
{
	A_dec retval = malloc_checked(sizeof(struct A_dec_t));

	retval->lineno = lineno;
	retval->type = A_Type_Dec;
	retval->self.typ = typ;
	return (retval);
}

/**
 *
 */
A_exp_list A_exp_List(A_exp head, A_exp_list tail)
{
	A_exp_list retval = malloc_checked(sizeof(struct A_exp_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}

/**
 *
 */
A_dec_list A_dec_List(A_dec head, A_dec_list tail)
{
	A_dec_list retval = malloc_checked(sizeof(struct A_dec_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}

/**
 *
 */
A_ty A_Namety(int lineno, S_symbol name)
{
	A_ty retval = malloc_checked(sizeof(struct A_ty_t));

	retval->lineno = lineno;
	retval->type = A_NameTy;
	retval->self.name = name;
	return (retval);
}

/**
 *
 */
A_ty A_record_ty(int lineno, A_field_list record)
{
	A_ty retval = malloc_checked(sizeof(struct A_ty_t));

	retval->lineno = lineno;
	retval->type = A_RecordTy;
	retval->self.record = record;
	return (retval);
}

/**
 *
 */
A_namety A_nameTy(S_symbol name, A_ty ty)
{
	A_namety retval = malloc_checked(sizeof(struct A_namety_t));

	retval->name = name;
	retval->ty = ty;
	return (retval);
}

/**
 *
 */
A_namety_list A_nameTy_list(A_namety head, A_namety_list tail)
{
	A_namety_list retval = malloc_checked(sizeof(struct A_namety_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}

/**
 *
 */
A_field A_Field(int lineno, S_symbol name, S_symbol typ)
{
	A_field retval = malloc_checked(sizeof(struct A_field_t));

	retval->lineno = lineno;
	retval->name = name;
	retval->typ = typ;
	retval->escape = TRUE;
	return (retval);
}

/**
 *
 */
A_field_list A_field_List(A_field head, A_field_list tail)
{
	A_field_list retval = malloc_checked(sizeof(struct A_field_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}

/**
 *
 */
A_efield A_eField(S_symbol name, A_exp exp)
{
	A_efield retval = malloc_checked(sizeof(struct A_efield_t));

	retval->name = name;
	retval->exp = exp;
	return (retval);
}

/**
 *
 */
A_efield_list A_eField_list(A_efield head, A_efield_list tail)
{
	A_efield_list retval = malloc_checked(sizeof(struct A_efield_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}

/**
 *
 */
A_func_dec A_function_Dec(int lineno, S_symbol return_type, S_symbol name, A_field_list params, A_exp body)
{
	A_func_dec retval = malloc_checked(sizeof(struct A_func_dec_t));

	retval->lineno = lineno;
	retval->return_type = return_type;
	retval->name = name;
	retval->params = params;
	retval->body = body;
	return (retval);
}

/**
 *
 */
A_func_dec_list A_func_Dec_list(A_func_dec head, A_func_dec_list tail)
{
	A_func_dec_list retval = malloc_checked(sizeof(struct A_func_dec_list_t));

	retval->head = head;
	retval->tail = tail;
	return (retval);
}
