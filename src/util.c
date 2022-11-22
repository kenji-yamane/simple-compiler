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
    fprintf(listing, "\t\ttype:   %s (%d)\n", tokenTypeToString(token), token);
}

void printOp(TokenType token) {
    switch (token) {
    case PLUS:
        fprintf(listing, "+\n");
        break;
    case MINUS:
        fprintf(listing, "-\n");
        break;
    case TIMES:
        fprintf(listing, "*\n");
        break;
    case OVER:
        fprintf(listing, "/\n");
        break;
    case LT:
        fprintf(listing, "<\n");
        break;
    case LTEQ:
        fprintf(listing, "<=\n");
        break;
    case GT:
        fprintf(listing, ">\n");
        break;
    case GTEQ:
        fprintf(listing, ">=\n");
        break;
    case EQ:
        fprintf(listing, "==\n");
        break;
    case NEQ:
        fprintf(listing, "!=\n");
        break;
    case ASSIGN:
        fprintf(listing, "=\n");
        break;
    default:
        fprintf(listing, "unexpected token, unable to print\n");
    }
}

char *tokenTypeToString(TokenType token) {
    switch (token) {
    case IF:
        return "IF";
    case ELSE:
        return "ELSE";
    case WHILE:
        return "WHILE";
    case INT:
        return "INT";
    case RETURN:
        return "RETURN";
    case VOID:
        return "VOID";
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case TIMES:
        return "TIMES";
    case OVER:
        return "OVER";
    case LT:
        return "LT";
    case LTEQ:
        return "LTEQ";
    case GT:
        return "GT";
    case GTEQ:
        return "GTEQ";
    case EQ:
        return "EQ";
    case NEQ:
        return "NEQ";
    case ASSIGN:
        return "ASSIGN";
    case SEMI:
        return "SEMI";
    case COMMA:
        return "COMMA";
    case LPAREN:
        return "LPAREN";
    case RPAREN:
        return "RPAREN";
    case LBRACK:
        return "LBRACK";
    case RBRACK:
        return "RBRACK";
    case LBRACE:
        return "LBRACE";
    case RBRACE:
        return "RBRACE";
    case NUM:
        return "NUM";
    case ID:
        return "ID";
    case ENDFILE:
        return "ENDFILE";
    case ERROR:
        return "ERROR";
    default: /* should never happen */
        return "UNKNOWN";
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

enum indentKinds { spaceIndent, vebarIndent, tIndent, lIndent };

enum indentKinds indent[100] = {spaceIndent};
int size = 0;

/* printNode prints the node text */
void printNode(TreeNode *node) {
    if (node->nodekind == StmtK) {
        switch (node->kind.stmt) {
        case IfK:
            fprintf(listing, "if\n");
            break;
        case RepeatK:
            fprintf(listing, "while\n");
            break;
        case AssignK:
            fprintf(listing, "assign\n");
            break;
        case ReturnK:
            fprintf(listing, "return\n");
            break;
        default:
            fprintf(listing, "unknown StmtNode kind\n");
            break;
        }
    } else if (node->nodekind == ExpK) {
        switch (node->kind.exp) {
        case OpK:
            fprintf(listing, "op: ");
            printOp(node->attr.op);
            break;
        case ConstK:
            fprintf(listing, "const: %d\n", node->attr.val);
            break;
        case IdK:
            fprintf(listing, "id: %s\n", node->attr.name);
            break;
        default:
            fprintf(listing, "unknown ExpNode kind\n");
            break;
        }
    } else if (node->nodekind == DeclK) {
        switch (node->kind.decl) {
        case VarK:
            fprintf(listing, "var ");
            break;
        case VecK:
            fprintf(listing, "vec ");
            break;
        case FunK:
            fprintf(listing, "fun ");
            break;
        default:
            fprintf(listing, "unknown DeclNode kind");
            break;
        }
        switch (node->type) {
        case Integer:
            fprintf(listing, "int\n");
            break;
        case Void:
            fprintf(listing, "void\n");
            break;
        default:
            fprintf(listing, "unknown DeclNode type\n");
            break;
        }
    } else
        fprintf(listing, "unknown node kind\n");
}

/* printSpaces indents by printing spaces */
void printSpaces() {
    for (int i = 0; i < size; i++)
        switch (indent[i]) {
        case spaceIndent:
            fprintf(listing, "  ");
            break;
        case vebarIndent:
            fprintf(listing, "│ ");
            break;
        case tIndent:
            fprintf(listing, "├─");
            break;
        case lIndent:
            fprintf(listing, "└─");
            break;
        }
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree) {
    while (tree != NULL) {
        printSpaces();
        printNode(tree);

        if (size > 0 && indent[size - 1] == tIndent)
            indent[size - 1] = vebarIndent;

        if (size > 0 && indent[size - 1] == lIndent)
            indent[size - 1] = spaceIndent;

        if (tree->sibling == NULL)
            indent[size++] = spaceIndent;
        else
            indent[size++] = vebarIndent;

        size++;
        for (int i = 0; i < MAXCHILDREN; i++) {
            if (tree->child[i + 1] == NULL)
                indent[size - 1] = lIndent;
            else
                indent[size - 1] = tIndent;

            printTree(tree->child[i]);
        }
        size--;

        tree = tree->sibling;
        size--;
    }
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

void echoSorce() {
    char c[2];
    int lineno = 1;

    fprintf(listing, "  1| ");
    while (fgets(c, 2, source)) {
        fprintf(listing, "%c", c[0]);
        if (c[0] == '\n')
            fprintf(listing, "%3d| ", ++lineno);
    }
    fprintf(listing, "\n");
    rewind(source);
}