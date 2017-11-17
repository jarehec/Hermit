#define SIZEOF 257
#define PTR_OP 258
#define INC_OP 259
#define DEC_OP 260
#define LEFT_OP 261
#define RIGHT_OP 262
#define LE_OP 263
#define GE_OP 264
#define EQ_OP 265
#define NE_OP 266
#define AND_OP 267
#define OR_OP 268
#define MUL_ASSIGN 269
#define DIV_ASSIGN 270
#define MOD_ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define LEFT_ASSIGN 274
#define RIGHT_ASSIGN 275
#define AND_ASSIGN 276
#define XOR_ASSIGN 277
#define OR_ASSIGN 278
#define TYPEDEF 279
#define EXTERN 280
#define STATIC 281
#define AUTO 282
#define REGISTER 283
#define INLINE 284
#define RESTRICT 285
#define CHAR 286
#define SHORT 287
#define INT 288
#define LONG 289
#define SIGNED 290
#define UNSIGNED 291
#define FLOAT 292
#define DOUBLE 293
#define CONST 294
#define VOLATILE 295
#define VOID 296
#define STRUCT 297
#define UNION 298
#define ENUM 299
#define ELLIPSIS 300
#define CASE 301
#define DEFAULT 302
#define IF 303
#define ELSE 304
#define SWITCH 305
#define WHILE 306
#define DO 307
#define FOR 308
#define GOTO 309
#define CONTINUE 310
#define BREAK 311
#define RETURN 312
#define DIGIT 313
#define IDENTIFIER 314
#define STRING_LITERAL 315
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
