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

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode *t, int scope) {
    TreeNode *l = t->child[0];
    TreeNode *r = t->child[1];
    BucketList lookup;
    bool isFunc;

    // printf("node: ");
    // printNode(t);

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
            } else
                t->type = lookup->type;
            break;
        }
        break;
    case StmtK:
        switch (t->kind.stmt) {
        case IfK:
            break;
        case AssignK:
            if (l->type != Integer)
                semanticError(l, "FIXME", "FIXME");
            if (r->type != Integer)
                semanticError(r, "FIXME", "assignment of non-integer value");
            t->type = Integer;
            break;
        case RepeatK:
        case ReturnK:
            break;
        }
        break;
    case DeclK:
        switch (t->kind.decl) {
        case FunK:
            isFunc = true;
            if (st_lookup(l->attr.name, scope) != NULL)
                semanticError(t, l->attr.name, "redeclaration of function");
            break;
        case VecK:
        case VarK:
            if (st_lookup(l->attr.name, scope) != NULL)
                semanticError(t, l->attr.name, "redeclaration of variable");
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
            st_insert(syntaxTree->child[0]->attr.name, syntaxTree->lineno,
                      scope, syntaxTree->type, syntaxTree->kind.decl);

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

void analyze(TreeNode *syntaxTree) {
    st_insert("input", 0, 0, Integer, FunK);
    st_insert("output", 0, 0, Void, FunK);

    return analyzeNode(syntaxTree, 0);
}