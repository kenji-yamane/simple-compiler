#ifndef _UTIL_H_
#define _UTIL_H_

#include "globals.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType, const char *);

/* Procedure printOp prints a char
 * representative of the operation
 */
void printOp(TokenType);

/* Simply prints the corresponding string
 * to the enum variable
 */
char *tokenTypeToString(TokenType);

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode *newStmtNode(StmtKind);

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind);

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode *newDeclNode(ExpType);

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char *copyString(char *);

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *);

/* Stack abstraction
 */
struct node {
    void *val;
    struct node *next;
};

typedef struct node *stack;

stack push(stack s, void *val);
void *front(stack s);
stack pop(stack s);

void echoSorce();

#endif
