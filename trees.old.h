#ifndef TREES_H
#define TREES_H

typedef enum {ADD, SUB, MUL, DIV} A_operator;

typedef struct A_var_t	*A_var;
typedef struct A_exp_t	*A_exp;
typedef struct A_dec_t	*A_dec;
typedef struct A_ty_t	*A_ty;

typedef struct A_exp_list_t			*A_exp_list;
typedef struct A_dec_list_t			*A_dec_list;
typedef struct A_namety_t			*A_namety;
typedef struct A_namety_list_t		*A_namety_list;
typedef struct A_field_t			*A_field;
typedef struct A_field_list_t		*A_field_list;
typedef struct A_efield_t			*A_efield;
typedef struct A_efield_list_t		*A_efield_list;
typedef struct A_func_dec_t			*A_func_dec;
typedef struct A_func_dec_list_t	*A_func_dec_list;

/**
 * A_dec_t - defines a declaration
 * @lineno: position of instruction
 */
struct A_dec_t {
	int lineno;
	enum {A_Func_Dec, A_Var_Dec, A_Type_Dec} type;
	union {
		A_func_dec_list function;
		struct {
			S_symbol var;
			S_symbol typ;
			A_exp init;
			bool escape;
		} var;
		A_namety_list typ;
	} self;
};

/**
 * A_ty_t - defines a type
 *
 */
struct A_ty_t {
	int lineno;
	enum {A_NameTy, A_RecordTy} type;
	union {
		S_symbol name;
		A_field_list record;
		S_symbol array;
	} self;
};
	
/**
 * A_var_t - defines a variable
 * todo
 */
struct A_var_t {
	int lineno;
	enum {A_SimpleVar, A_FieldVar, A_SubscriptVar} type;
	union {
		S_symbol simple;
		struct {
			A_var var;
			S_symbol sym;
		} field;
		struct {
			A_var var;
			A_exp exp;
		} subscript;
	} self;
};

/**
 * A_exp_t - defines an expression
 * todo
 */
struct A_exp_t {
	int lineno;
	enum {
		A_NullExp, A_IntExp, A_StringExp, A_VarExp, A_OpExp,
		A_CallExp, A_AssignExp, A_RecordExp, A_FuncExp
	} type;
	union {
		int int_exp;
		char *string_exp;
		A_var var;
		struct {
			A_operator oper;
			A_exp left;
			A_exp right;
		} op;
		struct {
			S_symbol func;
			A_exp_list args;
		} call_exp;
		struct {
			A_var var;
			A_exp exp;
		} assign;
		struct {
			S_symbol typ;
			A_efield_list fields;
		} record;
		struct {
			A_dec_list decs;
			A_exp body;
		} function;
	} self;
};

/**
 *
 */
struct A_func_dec_t {
	int lineno;
	S_symbol return_type;
	S_symbol name;
	A_field_list params;
	A_exp body;
};

/**
 *
 *
 */
struct A_func_dec_list_t {
	A_func_dec head;
	A_func_dec_list tail;
};

/**
 *
 *
 */
struct A_dec_list_t {
	A_dec head;
	A_dec_list tail;
};

/**
 *
 */
struct A_namety_t {
	S_symbol name;
	A_ty ty;
};

/**
 *
 */
struct A_namety_list_t {
	A_namety head;
	A_namety_list tail;
};

/**
 * 	
 */
struct A_field_t {
	int lineno;
	S_symbol name, typ;
	bool escape;
};

/**
 *
 */
struct A_field_list_t {
	A_field head;
	A_field_list tail;
};

/**
 *
 */
struct A_exp_list_t {
	A_exp head;
	A_exp_list tail;
};
/**
 * 	
 */
struct A_efield_t {
	S_symbol name;
	A_exp exp;
};

/**
 *
 */
struct A_efield_list_t {
	A_efield head;
	A_efield_list tail;
};

A_var A_simple_var(int lineno, S_symbol sym);
A_var A_field_var(int lineno, A_var var, S_symbol sym);
A_var A_subscript_var(int lineno, A_var var, A_exp exp);

A_exp A_var_exp(int lineno, A_var var);
A_exp A_null_exp(int lineno);
A_exp A_int_exp(int lineno, int value);
A_exp A_string_exp(int lineno, char *str);
A_exp A_call_exp(int lineno, S_symbol func, A_exp_list args);
A_exp A_op_exp(int lineno, A_operator op, A_exp left, A_exp right);
A_exp A_record_exp(int lineno, S_symbol typ, A_efield_list fields);
A_exp A_assign_exp(int lineno, A_var var, A_exp exp);
A_exp A_program(int lineno, A_dec_list decs, A_exp body);

A_dec A_func_Dec(int lineno, A_func_dec_list function);
A_dec A_var_Dec(int lineno, S_symbol var, S_symbol typ, A_exp init);
A_dec A_type_Dec(int lineno, A_namety_list type);

A_exp_list A_exp_List(A_exp head, A_exp_list tail);
A_dec_list A_dec_List(A_dec head, A_dec_list tail);
A_ty A_Namety(int lineno, S_symbol name);
A_ty A_record_ty(int lineno, A_field_list record);
A_namety A_nameTy(S_symbol name, A_ty ty);
A_namety_list A_nameTy_list(A_namety head, A_namety_list tail);
A_field A_Field(int lineno, S_symbol name, S_symbol typ);
A_field_list A_field_List(A_field head, A_field_list tail);
A_efield A_eField(S_symbol name, A_exp exp);
A_efield_list A_eField_list(A_efield head, A_efield_list tail);
A_func_dec A_function_Dec(int lineno, S_symbol return_type, S_symbol name, A_field_list params, A_exp body);
A_func_dec_list A_func_Dec_list(A_func_dec head, A_func_dec_list tail);

#endif
