/********************************************************/
/* File: analyze.c                                      */
/* Semantic analyzer implementation for the C- compiler */
/* Compiler Construction: Principles and Practice       */
/* Kenneth C. Louden                                    */
/********************************************************/

#include "analyze.h"
#include "globals.h"
#include "symtab.h"

/* counter for variable memory locations */
static int location = 0;

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by t
 */

static void semanticError(TreeNode *t, char *name, char *message) {
    fprintf(listing, "Semantic error for '%s' at line %d: %s\n", name,
            t->lineno, message);
    Error = TRUE;
}

static int paramCount(TreeNode *t) {
    if (t->nodekind != ExpK && t->kind.exp != IdK)
        return 0;

    int count = 0;
    for (TreeNode *param = t->child[0]; param != NULL; param = param->sibling)
        count++;
    return count;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode *t, int scope) {
    TreeNode *l = t->child[0];
    TreeNode *r = t->child[1];
    BucketList lookup;
    char *name;

    switch (t->nodekind) {
    case ExpK:
        switch (t->kind.exp) {
        case OpK:
            if (l->type == Void)
                semanticError(t, "operation",
                              "left-side of operation returns void");
            if (r->type == Void)
                semanticError(t, "operation",
                              "right-side of operation returns void");
        case ConstK:
            t->type = Integer;
            break;
        case IdK:
            lookup = st_lookup(t->attr.name, scope);
            if (lookup == NULL) {
                semanticError(t, t->attr.name,
                              "name was not declared in current scope");
                t->type = Integer; // conferir se tem que setar para inteiro ou
                                   // deixar void...
                break;
            }
            t->type = lookup->type;
            if (paramCount(t) != lookup->params) {
                char message[100] = "";
                sprintf(message,
                        "parameter counting mismatch (expected %d, found %d)",
                        lookup->params, paramCount(t));
                semanticError(t, t->attr.name, message);
            }
            break;
        }
        break;
    case StmtK:
        switch (t->kind.stmt) {
        case IfK:
            break;
        case AssignK:
            if (l->type != Integer)
                semanticError(l, "FIXME1", "FIXME");
            if (r->type != Integer)
                semanticError(r, l->attr.name,
                              "assignment of non-integer value to variable");
            t->type = Integer;
            break;
        case RepeatK:
        case ReturnK:
            break;
        }
        break;
    case DeclK:
        name = l->attr.name;
        switch (t->kind.decl) {
        case FunK:
            if (st_lookup(name, scope) != NULL)
                semanticError(t, name, "invalid redeclaration of function");
            break;
        case VecK:
        case VarK:
            if (st_lookup(name, scope) != NULL)
                semanticError(t, name, "invalid redeclaration of variable");
            if (t->type == Void)
                semanticError(t, name, "invalid declaration for variable");
            break;
        }
        break;
    }
}

void analyzeNode(TreeNode *syntaxTree, int scope) {
    TreeNode *child;

    while (syntaxTree != NULL) {
        if (syntaxTree->nodekind == DeclK) {
            checkNode(syntaxTree, scope);

            // We should count the param number
            int count = paramCount(syntaxTree->child[0]);
            st_insert(syntaxTree->child[0]->attr.name, syntaxTree->lineno,
                      scope, syntaxTree->type, syntaxTree->kind.decl, count);

            for (int i = 0; i < MAXCHILDREN; i++) {
                child = syntaxTree->child[0]->child[i];
                if (child == NULL)
                    continue;
                analyzeNode(child, scope);
            }
        } else {
            for (int i = 0; i < MAXCHILDREN; i++) {
                child = syntaxTree->child[i];
                if (child == NULL)
                    continue;
                analyzeNode(child, scope);
            }
            checkNode(syntaxTree, scope);
        }

        syntaxTree = syntaxTree->sibling;
    }
}

void analyzeMain(TreeNode *syntaxTree) {
    while (syntaxTree->sibling != NULL)
        syntaxTree = syntaxTree->sibling;

    TreeNode *func = syntaxTree->child[0];

    if (strcmp(func->attr.name, "main") != 0)
        semanticError(func, "main", "last declaration is not main");
    else {
        if (paramCount(func) > 0)
            semanticError(func, "main", "main should not have parameters");
        if (syntaxTree->type != Void)
            semanticError(func, "main", "main should return void");
    }
}

void analyze(TreeNode *syntaxTree) {
    st_insert("input", 0, 0, Integer, FunK, 0);
    st_insert("output", 0, 0, Void, FunK, 1);

    analyzeNode(syntaxTree, 0);

    // Check for main
    analyzeMain(syntaxTree);
}