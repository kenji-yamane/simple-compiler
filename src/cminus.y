/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}


%token ENDFILE, ERROR
%token IF, ELSE, WHILE, INT, RETURN, VOID
%token ID, NUM
%token PLUS, MINUS, TIMES, OVER, LT, LTEQ, GT, GTEQ, EQ,
    NEQ, ASSIGN, SEMI, COMMA, LPAREN, RPAREN, LBRACK, RBRACK, LBRACE, RBRACE 


%% /* Grammar for C- */

programa
    : decl_lista { savedTree = $1; }
    ;

decl_lista    
    : decl_lista decl
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL)
                    t = t->sibling;
                t->sibling = $2;
                $$ = $1;
            } else
                $$ = $2;
        }
    | decl { $$ = $1; }
    ;

decl
    : var_decl
    | fun_decl
    ;

var_decl
    : tipo ID SEMI
    | tipo ID LBRACK NUM RBRACK SEMI
    ;

tipo
    : INT
    | VOID
    ;

fun_decl
    : tipo ID LPAREN params RPAREN comp_decl
    ;

params
    : params_seq
    | VOID
    ;

params_seq
    : params_seq COMMA param
    | param
    ;

param
    : tipo ID
    | tipo ID LBRACK RBRACK
    ;

comp_decl
    : LBRACE local_decl stmt_lista RBRACE
    ;

local_decl
    : local_decl var_decl
    | vazio
    ;

stmt_lista
    : stmt_lista stmt
    | vazio
    ;

stmt
    : expr_decl
    | comp_decl
    | selc_decl
    | iter_decl
    | retr_decl
    ;

expr_decl
    : exp SEMI
    | SEMI
    ;

selc_decl
    : IF LPAREN exp RPAREN stmt
    | IF LPAREN exp RPAREN stmt ELSE stmt
    ;

iter_decl
    : WHILE LPAREN exp RPAREN stmt
    ;

retr_decl
    : RETURN SEMI
    | RETURN exp SEMI
    ;

exp
    : var ASSIGN exp
    | smp_exp
    ;

var
    : ID
    | ID LBRACK exp RBRACK
    ;

smp_exp
    : soma_exp rel soma_exp
    | soma_exp
    ;

rel
    : LTEQ
    | LT
    | GTEQ
    | GT
    | EQ
    | NEQ
    ;

soma_exp
    : soma_exp soma termo
    | termo
    ;

soma
    : PLUS
    | MINUS
    ;

termo
    : termo mult fator
    | fator
    ;

mult
    : TIMES
    | OVER
    ;

fator
    : LPAREN exp RPAREN
    | var
    | ativacao
    | NUM
    ;

ativacao
    : ID LPAREN args RPAREN
    ;

args
    : arg_lista
    | vazio

arg_lista
    : arg_lista COMMA exp
    | exp
    ;


%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

