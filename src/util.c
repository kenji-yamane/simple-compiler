#include "util.h"
#include "globals.h"

/* Procedure printToken prints a token
 * and its lexeme to the listing file
 */
void printToken(TokenType token, const char *tokenString) {
    switch (token) {
    case IF:
    case ELSE:
    case WHILE:
    case INT:
    case RETURN:
    case VOID:
        fprintf(listing, "\treserved word:\n");
        break;
    case PLUS:
    case MINUS:
    case TIMES:
    case OVER:
    case LT:
    case LTEQ:
    case GT:
    case GTEQ:
    case EQ:
    case NEQ:
    case ASSIGN:
    case SEMI:
    case COMMA:
    case LPAREN:
    case RPAREN:
    case LBRACK:
    case RBRACK:
    case LBRACE:
    case RBRACE:
        fprintf(listing, "\tspecial symbol:\n");
        break;
    case NUM:
        fprintf(listing, "\tnumber:\n");
        break;
    case ID:
        fprintf(listing, "\tidentifier:\n");
        break;
    case ENDFILE:
        fprintf(listing, "\ttrace:\n");
        break;
    case ERROR:
        fprintf(listing, "\terror:\n");
        break;
    default: /* should never happen */
        fprintf(listing, "\tunknown:        %d\n", token);
    }
    fprintf(listing, "\t\tlexeme: \"%s\"\n", tokenString);
    fprintf(listing, "\t\ttype:   ");
    tokenTypeToString(token);
    fprintf(listing, "\n");
}

void tokenTypeToString(TokenType token) {
    switch (token) {
    case IF:
        fprintf(listing, "IF");
        break;
    case ELSE:
        fprintf(listing, "ELSE");
        break;
    case WHILE:
        fprintf(listing, "WHILE");
        break;
    case INT:
        fprintf(listing, "INT");
        break;
    case RETURN:
        fprintf(listing, "RETURN");
        break;
    case VOID:
        fprintf(listing, "VOID");
        break;
    case PLUS:
        fprintf(listing, "PLUS");
        break;
    case MINUS:
        fprintf(listing, "MINUS");
        break;
    case TIMES:
        fprintf(listing, "TIMES");
        break;
    case OVER:
        fprintf(listing, "OVER");
        break;
    case LT:
        fprintf(listing, "LT");
        break;
    case LTEQ:
        fprintf(listing, "LTEQ");
        break;
    case GT:
        fprintf(listing, "GT");
        break;
    case GTEQ:
        fprintf(listing, "GTEQ");
        break;
    case EQ:
        fprintf(listing, "EQ");
        break;
    case NEQ:
        fprintf(listing, "NEQ");
        break;
    case ASSIGN:
        fprintf(listing, "ASSIGN");
        break;
    case SEMI:
        fprintf(listing, "SEMI");
        break;
    case COMMA:
        fprintf(listing, "COMMA");
        break;
    case LPAREN:
        fprintf(listing, "LPAREN");
        break;
    case RPAREN:
        fprintf(listing, "RPAREN");
        break;
    case LBRACK:
        fprintf(listing, "LBRACK");
        break;
    case RBRACK:
        fprintf(listing, "RBRACK");
        break;
    case LBRACE:
        fprintf(listing, "LBRACE");
        break;
    case RBRACE:
        fprintf(listing, "RBRACE");
        break;
    case NUM:
        fprintf(listing, "NUM");
        break;
    case ID:
        fprintf(listing, "ID");
        break;
    case ENDFILE:
        fprintf(listing, "ENDFILE");
        break;
    case ERROR:
        fprintf(listing, "ERROR");
        break;
    default: /* should never happen */
        fprintf(listing, "\tunknown:        %d\n", token);
    }
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode *newStmtNode(StmtKind kind) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    else {
        for (i = 0; i < MAXCHILDREN; i++)
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode *newExpNode(ExpKind kind) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    else {
        for (i = 0; i < MAXCHILDREN; i++)
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.exp = kind;
        t->lineno = lineno;
        t->type = Void;
    }
    return t;
}

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode *newDeclNode(ExpType type) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    else {
        for (i = 0; i < MAXCHILDREN; i++)
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = DeclK;
        t->lineno = lineno;
        t->type = type;
    }
    return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char *copyString(char *s) {
    int n;
    char *t;
    if (s == NULL)
        return NULL;
    n = strlen(s) + 1;
    t = malloc(n);
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n", lineno);
    else
        strcpy(t, s);
    return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno += 2
#define UNINDENT indentno -= 2

/* printSpaces indents by printing spaces */
static void printSpaces(void) {
    int i;
    for (i = 0; i < indentno; i++)
        fprintf(listing, " ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree) {
    int i;
    INDENT;
    while (tree != NULL) {
        printSpaces();
        if (tree->nodekind == StmtK) {
            switch (tree->kind.stmt) {
            case IfK:
                fprintf(listing, "if\n");
                break;
            case RepeatK:
                fprintf(listing, "while\n");
                break;
            case AssignK:
                fprintf(listing, "=\n");
                break;
            case ReturnK:
                fprintf(listing, "return\n");
                break;
            default:
                fprintf(listing, "Unknown StmtNode kind\n");
                break;
            }
        } else if (tree->nodekind == ExpK) {
            switch (tree->kind.exp) {
            case OpK:
                fprintf(listing, "Op: ");
                printToken(tree->attr.op, "\0");
                break;
            case ConstK:
                fprintf(listing, "Const: %d\n", tree->attr.val);
                break;
            case IdK:
                fprintf(listing, "Id: %s\n", tree->attr.name);
                break;
            default:
                fprintf(listing, "Unknown ExpNode kind\n");
                break;
            }
        } else if (tree->nodekind = DeclK) {
            switch (tree->kind.decl) {
            case VarK:
                fprintf(listing, "Decl: var ");
                break;
            case VecK:
                fprintf(listing, "Decl: vec ");
                break;
            case FunK:
                fprintf(listing, "Decl: fun ");
                break;
            default:
                fprintf(listing, "Unknown DeclNode kind\n");
                break;
            }
            switch (tree->type) {
            case Integer:
                fprintf(listing, "int\n");
                break;
            case Void:
                fprintf(listing, "void\n");
                break;
            case Boolean:
                fprintf(listing, "boolean\n");
                break;
            default:
                fprintf(listing, "Unknown DeclNode type\n");
                break;
            }
        } else
            fprintf(listing, "Unknown node kind\n");
        for (i = 0; i < MAXCHILDREN; i++)
            printTree(tree->child[i]);
        tree = tree->sibling;
    }
    UNINDENT;
}

stack push(stack s, void *val) {
    struct node *n = malloc(sizeof(struct node));
    n->val = val;
    n->next = (struct node *)s;
    return n;
}

void *front(stack s) { return s->val; }

stack pop(stack s) {
    struct node *head = s;
    s = (stack)s->next;
    free(head);
    return s;
}
