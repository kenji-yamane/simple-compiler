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

static stack savedName; /* for use in assignments */
static stack savedLine;  /* ditto */

static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}


%start programa
%token ENDFILE ERROR
%token IF WHILE INT RETURN VOID
%token ID NUM
%token SEMI COMMA LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%left PLUS MINUS TIMES OVER LT LTEQ GTEQ EQ NEQ GT ASSIGN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


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
    : var_decl { $$ = $1; }
    | fun_decl { $$ = $1; }
    ;

var_decl
    : tipo ID        
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        }
      SEMI
        {
            $$ = $1;
            $$->kind.decl = VarK;
            $$->child[0] = newExpNode(IdK);
            $$->child[0]->attr.name = front(savedName);
            $$->child[0]->lineno = (int) front(savedLine);
            
            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    | tipo ID
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        }
      LBRACK NUM
        {
            savedName = push(savedName, copyString(numberString));
            savedLine = push(savedLine, (void*) lineno);
        }
      RBRACK SEMI
        {
            $$ = $1;
            $$->kind.decl = VecK;
            
            $$->child[1] = newExpNode(ConstK);
            $$->child[1]->attr.val = atoi(front(savedName));
            $$->child[1]->lineno = (int) front(savedLine);
            savedName = pop(savedName);
            savedLine = pop(savedLine);
            
            $$->child[0] = newExpNode(IdK);
            $$->child[0]->attr.name = front(savedName);
            $$->child[0]->lineno = (int) front(savedLine);
            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    ;

tipo
    : INT 
        { 
            $$ = newDeclNode(Integer);
        }
    | VOID 
        { 
            $$ = newDeclNode(Void);
        }
    ;

fun_decl
    : tipo ID
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        }
      LPAREN params RPAREN comp_decl
        {
            $$ = $1;
            $$->kind.decl = FunK;
            $$->child[0] = newExpNode(IdK);
            $$->child[0]->attr.name = front(savedName);
            $$->child[0]->lineno = (int) front(savedLine);
            $$->child[0]->child[0] = $5;
            $$->child[0]->child[1] = $7;

            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    ;

params
    : params_seq { $$ = $1; }
    | VOID { $$ = NULL; }
    ;

params_seq
    : params_seq COMMA param
        {
            YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL)
                    t = t->sibling;
                t->sibling = $3;
                $$ = $1;
            } else {
                $$ = $3;
            }
        }
    | param { $$ = $1; }
    ;

param
    : tipo ID
        {
            $$ = $1;
            $$->kind.decl = VarK;
            $$->child[0] = newExpNode(IdK);
            $$->child[0]->attr.name = copyString(identifierString);
        }
    | tipo ID
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        }
      LBRACK RBRACK
        {
            $$ = $1;
            $$->kind.decl = VecK;
            $$->child[0] = newExpNode(IdK);
            $$->child[0]->attr.name = front(savedName);
            $$->child[0]->lineno = (int) front(savedLine);

            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    | error { $$ = NULL; }
    ;

comp_decl
    : LBRACE local_decl stmt_lista RBRACE
        {
            YYSTYPE t = $2;
            if ($2 != NULL) {
                while(t->sibling != NULL)
                    t = t->sibling;
                t->sibling = $3;
                $$ = $2;
            } else
                $$ = $3;
        }
    ;

local_decl
    : local_decl var_decl
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
    | %empty { $$ = NULL; }
    ;

stmt_lista
    : stmt_lista stmt
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
    | %empty { $$ = NULL; }
    ;

stmt
    : expr_decl { $$ = $1; }
    | comp_decl { $$ = $1; }
    | selc_decl { $$ = $1; }
    | iter_decl { $$ = $1; }
    | retr_decl { $$ = $1; }
    ;

expr_decl
    : exp SEMI { $$ = $1; }
    | SEMI { $$ = NULL; }
    ;

selc_decl
    : IF LPAREN exp RPAREN stmt %prec LOWER_THAN_ELSE
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
        }
    | IF LPAREN exp RPAREN stmt ELSE stmt
        {
            $$ = newStmtNode(IfK);
            $$->child[0] = $3;
            $$->child[1] = $5;
            $$->child[2] = $7;
        }
    ;

iter_decl
    : WHILE LPAREN exp RPAREN stmt
        {
            $$ = newStmtNode(RepeatK);
            $$->child[0] = $3;
            $$->child[1] = $5;
        }
    ;

retr_decl
    : RETURN SEMI
        {
            $$ = newStmtNode(ReturnK);
        }
    | RETURN exp SEMI
        {
            $$ = newStmtNode(ReturnK);
            $$->child[0] = $2;
        }
    ;

exp
    : var ASSIGN exp 
    {
        $$ = newStmtNode(AssignK);
        $$->child[0] = $1;
        $$->child[1] = $3;
    }
    | smp_exp { $$ = $1; }
    ;

var
    : ID
        {
            $$ = newExpNode(IdK);
            $$->attr.name = copyString(identifierString);
        }
    | ID
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        }
      LBRACK exp RBRACK
        {
            $$ = newExpNode(IdK);
            $$->child[0] = $4;
            $$->attr.name = front(savedName);
            $$->lineno = (int) front(savedLine);

            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    ;

 smp_exp
    : soma_exp rel soma_exp 
        {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | soma_exp { $$ = $1; }
    ;

rel
    : LTEQ { $$ = newExpNode(OpK); $$->attr.op = LTEQ; }
    | LT   { $$ = newExpNode(OpK); $$->attr.op = LT; }
    | GTEQ { $$ = newExpNode(OpK); $$->attr.op = GTEQ; }
    | GT   { $$ = newExpNode(OpK); $$->attr.op = GT; }
    | EQ   { $$ = newExpNode(OpK); $$->attr.op = EQ; }
    | NEQ  { $$ = newExpNode(OpK); $$->attr.op = NEQ; }
    ;

soma_exp
    : soma_exp soma termo
        {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | termo { $$ = $1; }
    ;

soma
    : PLUS  { $$ = newExpNode(OpK); $$->attr.op = PLUS; }
    | MINUS { $$ = newExpNode(OpK); $$->attr.op = MINUS; }
    ;

termo
    : termo mult fator
        {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
        }
    | fator { $$ = $1; }
    ;

mult
    : TIMES { $$ = newExpNode(OpK); $$->attr.op = TIMES; }
    | OVER { $$ = newExpNode(OpK); $$->attr.op = OVER; }
    ;

fator
    : LPAREN exp RPAREN { $$ = $2; }
    | var { $$ = $1; }
    | ativacao { $$ = $1; }
    | NUM 
        {
            $$ = newExpNode(ConstK);
            $$->attr.val = atoi(numberString);
        }
    ;

ativacao
    : ID
        {
            savedName = push(savedName, copyString(identifierString));
            savedLine = push(savedLine, (void*) lineno);
        } 
      LPAREN args RPAREN
        {
            $$ = newExpNode(IdK);
            $$->child[0] = $4;
            $$->attr.name = front(savedName);
            $$->lineno = (int) front(savedLine);
            
            savedName = pop(savedName);
            savedLine = pop(savedLine);
        }
    ;

args
    : arg_lista { $$ = $1; }
    | %empty { $$ = NULL; }
    ;

arg_lista
    : arg_lista COMMA exp
    {
        YYSTYPE t = $1;
            if (t != NULL) {
                while (t->sibling != NULL)
                    t = t->sibling;
                t->sibling = $3;
                $$ = $1;
            } else
                $$ = $3;
        
    }
    | exp { $$ = $1; }
    ;

%%

int yyerror(char * message) {
    fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
    fprintf(listing,"Current token: ");
    printToken(yychar,tokenString);
    Error = TRUE;
    return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void) {
    return getToken();
}

TreeNode * parse(void) {
    yyparse();
    return savedTree;
}

