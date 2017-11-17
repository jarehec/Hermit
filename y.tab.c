#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "grammar.y"
#include "util.h"
#include "trees.h"
int yylex();
void yyerror(const char *s);
extern int yylineno;
A_program prog_root;

#line 24 "grammar.y"
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
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    5,    1,    1,    1,    8,    8,    8,    7,    7,    7,
    6,   12,   15,   15,   13,   13,   14,   14,   11,   11,
   11,    9,    9,   10,   10,    2,    2,    2,    4,    3,
    3,    0,
};
static const short yylen[] = {                            2,
    1,    1,    1,    1,    1,    3,    3,    1,    3,    3,
    1,    4,    3,    5,    2,    5,    1,    1,    1,    1,
    1,    1,    2,    2,    3,    1,    2,    0,    6,    1,
    2,    1,
};
static const short yydefred[] = {                         0,
    3,    2,    4,    0,    0,   32,    0,    0,   31,    0,
    0,    0,   27,    0,    0,   29,    0,    1,    0,   24,
    0,    5,   21,    0,    0,    0,   22,   17,   18,   20,
   19,   15,    0,    0,    0,    0,    0,    0,    0,   25,
   23,    0,    0,    0,   13,    0,    0,    6,    7,    0,
   12,    0,   16,   14,
};
static const short yydgoto[] = {                          4,
    5,   12,    6,    7,   22,   23,   24,   25,   26,   16,
   27,   28,   29,   30,   31,
};
static const short yysindex[] = {                      -276,
    0,    0,    0,    0, -300,    0, -276,  -17,    0, -276,
 -279,   -5,    0,  -86, -124,    0,  -31,    0,  -22,    0,
 -274,    0,    0,  -28,  -15, -121,    0,    0,    0,    0,
    0,    0, -275, -275,  -35, -275, -275, -275, -275,    0,
    0,    1,  -18, -275,    0,  -15,  -15,    0,    0,  -16,
    0,  -14,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   44,    0,    0,    5,
    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -52,  -43,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -40,  -37,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    3,    0,   41,    0,   -8,  -23,    0,   -3,    0,    0,
   23,    0,    0,    0,    0,
};
#define YYTABLESIZE 277
static const short yytable[] = {                          8,
   20,    8,    9,   40,    9,   10,   11,   10,   33,    1,
   43,    2,   11,    8,   36,    8,   37,   21,    9,    3,
   52,   10,   10,   45,   42,   44,   38,   32,   21,   48,
   49,   39,   46,   47,   13,   14,   15,   18,   34,   35,
   51,   50,   53,   30,   54,   28,   26,    9,   41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   11,    0,    0,    0,    0,    0,    0,    0,
    0,    8,    0,    0,    9,    0,    0,   10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    2,    1,    0,    2,    0,    0,    0,
    0,    3,    0,    0,    3,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   17,   18,   19,
   17,   18,   19,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   11,    0,   11,    0,    0,    0,    0,
    0,    0,    8,   11,    8,    9,    0,    9,   10,    0,
   10,    0,    8,    0,    0,    9,    0,    0,   10,   11,
   11,   11,    0,    0,    0,    0,    0,    0,    8,    8,
    8,    9,    9,    9,   10,   10,   10,
};
static const short yycheck[] = {                         43,
  125,   45,   43,  125,   45,   43,   59,   45,   40,  286,
   34,  288,   10,  314,   43,   59,   45,   15,   59,  296,
   44,   59,   40,   59,   33,   61,   42,   59,   26,   38,
   39,   47,   36,   37,  314,   41,  123,  313,   61,  314,
   59,   41,   59,    0,   59,   41,   41,    7,   26,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,  125,   -1,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  286,   -1,  288,  286,   -1,  288,   -1,   -1,   -1,
   -1,  296,   -1,   -1,  296,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  312,  313,  314,
  312,  313,  314,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,   -1,  288,   -1,   -1,   -1,   -1,
   -1,   -1,  286,  296,  288,  286,   -1,  288,  286,   -1,
  288,   -1,  296,   -1,   -1,  296,   -1,   -1,  296,  312,
  313,  314,   -1,   -1,   -1,   -1,   -1,   -1,  312,  313,
  314,  312,  313,  314,  312,  313,  314,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",
0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"SIZEOF","PTR_OP","INC_OP","DEC_OP","LEFT_OP","RIGHT_OP","LE_OP","GE_OP",
"EQ_OP","NE_OP","AND_OP","OR_OP","MUL_ASSIGN","DIV_ASSIGN","MOD_ASSIGN",
"ADD_ASSIGN","SUB_ASSIGN","LEFT_ASSIGN","RIGHT_ASSIGN","AND_ASSIGN",
"XOR_ASSIGN","OR_ASSIGN","TYPEDEF","EXTERN","STATIC","AUTO","REGISTER","INLINE",
"RESTRICT","CHAR","SHORT","INT","LONG","SIGNED","UNSIGNED","FLOAT","DOUBLE",
"CONST","VOLATILE","VOID","STRUCT","UNION","ENUM","ELLIPSIS","CASE","DEFAULT",
"IF","ELSE","SWITCH","WHILE","DO","FOR","GOTO","CONTINUE","BREAK","RETURN",
"DIGIT","IDENTIFIER","STRING_LITERAL","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"value : DIGIT",
"type : INT",
"type : CHAR",
"type : VOID",
"multiplicative_expression : value",
"multiplicative_expression : multiplicative_expression '*' value",
"multiplicative_expression : multiplicative_expression '/' value",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression '+' multiplicative_expression",
"additive_expression : additive_expression '-' multiplicative_expression",
"expression : additive_expression",
"assignment_statement : IDENTIFIER '=' expression ';'",
"declaration : type IDENTIFIER ';'",
"declaration : type IDENTIFIER '=' expression ';'",
"return_statement : RETURN ';'",
"return_statement : RETURN '(' value ')' ';'",
"statements : assignment_statement",
"statements : return_statement",
"block_item : declaration",
"block_item : statements",
"block_item : expression",
"block_item_list : block_item",
"block_item_list : block_item_list block_item",
"block_statements : '{' '}'",
"block_statements : '{' block_item_list '}'",
"params : type",
"params : type IDENTIFIER",
"params :",
"function : type IDENTIFIER '(' params ')' block_statements",
"function_list : function",
"function_list : function function_list",
"program : function_list",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 58 "grammar.y"
	{ yyval.exp = int_expression(1, yystack.l_mark[0].integer_val.val); }
break;
case 2:
#line 62 "grammar.y"
	{ yyval.str = yystack.l_mark[0].string_val.val; }
break;
case 3:
#line 63 "grammar.y"
	{ yyval.str = yystack.l_mark[0].string_val.val; }
break;
case 4:
#line 64 "grammar.y"
	{ yyval.str = yystack.l_mark[0].string_val.val; }
break;
case 6:
#line 69 "grammar.y"
	{ }
break;
case 7:
#line 70 "grammar.y"
	{ }
break;
case 12:
#line 84 "grammar.y"
	{ /*$$ = assign_statement(1, $1, $3);*/ }
break;
case 13:
#line 88 "grammar.y"
	{ yyval.stm = var_dec_statement(yystack.l_mark[-1].string_val.lineno, yystack.l_mark[-2].str, yystack.l_mark[-1].string_val.val, 1, NULL); }
break;
case 14:
#line 89 "grammar.y"
	{ yyval.stm = var_dec_statement(yystack.l_mark[-3].string_val.lineno, yystack.l_mark[-4].str, yystack.l_mark[-3].string_val.val, 1, yystack.l_mark[-1].exp); }
break;
case 15:
#line 93 "grammar.y"
	{ yyval.stm = return_statement(1, NULL); }
break;
case 16:
#line 94 "grammar.y"
	{ yyval.stm = return_statement(1, yystack.l_mark[-2].exp); }
break;
case 17:
#line 98 "grammar.y"
	{ yyval.stm = yystack.l_mark[0].stm; }
break;
case 18:
#line 99 "grammar.y"
	{ yyval.stm = yystack.l_mark[0].stm; }
break;
case 19:
#line 103 "grammar.y"
	{ yyval.stm = yystack.l_mark[0].stm; }
break;
case 20:
#line 104 "grammar.y"
	{ yyval.stm = yystack.l_mark[0].stm; }
break;
case 21:
#line 105 "grammar.y"
	{ /*$$ = $1;*/ }
break;
case 22:
#line 109 "grammar.y"
	{ yyval.stm_list = statement_list(1, yystack.l_mark[0].stm, NULL); }
break;
case 23:
#line 110 "grammar.y"
	{ yyval.stm_list = statement_list(1, yystack.l_mark[0].stm, yystack.l_mark[-1].stm_list); }
break;
case 24:
#line 114 "grammar.y"
	{ yyval.stm_list = statement_list(1, empty_statement(1), NULL); }
break;
case 25:
#line 115 "grammar.y"
	{ yyval.stm_list = yystack.l_mark[-1].stm_list; }
break;
case 26:
#line 119 "grammar.y"
	{ yyval.param_list = parameter_list(1, parameter(1, yystack.l_mark[0].str, NULL, 1), NULL); }
break;
case 27:
#line 120 "grammar.y"
	{ yyval.param_list = parameter_list(yystack.l_mark[0].string_val.lineno, parameter(yystack.l_mark[0].string_val.lineno, yystack.l_mark[-1].str, yystack.l_mark[0].string_val.val, 1), NULL); }
break;
case 28:
#line 121 "grammar.y"
	{ yyval.param_list = parameter_list(1, parameter(1, NULL, NULL, 1), NULL); }
break;
case 29:
#line 125 "grammar.y"
	{ yyval.func_dec = function_def(yystack.l_mark[-4].string_val.lineno, yystack.l_mark[-5].str, yystack.l_mark[-4].string_val.val, yystack.l_mark[-2].param_list, yystack.l_mark[0].stm_list); }
break;
case 30:
#line 129 "grammar.y"
	{ yyval.func_dec_list = function_dec_list(1, yystack.l_mark[0].func_dec, NULL); }
break;
case 31:
#line 130 "grammar.y"
	{ yyval.func_dec_list = function_dec_list(1, yystack.l_mark[-1].func_dec, yystack.l_mark[0].func_dec_list); }
break;
case 32:
#line 134 "grammar.y"
	{ A_root = program(1, yystack.l_mark[0].func_dec_list); }
break;
#line 657 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
