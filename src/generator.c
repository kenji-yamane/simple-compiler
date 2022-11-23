#include "generator.h"

int rCnt = 0;

int getNewRegister() { return rCnt++; }

void printRegister(int r) { fprintf(listing, "r%d", r); }

void printChar(char c) { fprintf(listing, "%c", c); }

void generateTree(TreeNode *t) {
    if (t == NULL) {
        return;
    }
    switch (t->nodekind) {
    case StmtK:
        break;
    case ExpK:
        break;
    case DeclK:
        break;
    }
}

void generateStatement(TreeNode *t) {
    if (t == NULL) {
        return;
    }
    switch (t->kind.exp) {
    case IfK:
        break;
    case RepeatK:
        break;
    case AssignK:
        break;
    case ReturnK:
        break;
    }
}

void generateExpression(TreeNode *t, int finalRegister) {
    if (t == NULL) {
        return;
    }
    switch (t->kind.exp) {
    case OpK:
        int left = getNewRegister(), right = getNewRegister();
        generateExpression(t->child[0], left);
        generateExpression(t->child[0], right);
        printRegister(finalRegister);
        fprintf(listing, " = ");
        printRegister(left);
        printChar(' ');
        printOp(t->attr.op);
        printChar(' ');
        printRegister(right);
        printChar('\n');
        break;
    case ConstK:
        printRegister(finalRegister);
        fprintf(listing, " = ");
        fprintf(listing, "%d", t->attr.val);
        break;
    case IdK:
        if ()
            break;
    }
}

void generateDeclaration(TreeNode *t) {
    if (t == NULL) {
        return;
    }
    switch (t->kind.exp) {
    case VarK:
    case VecK:
    case IdK:
        break;
    }
}

void generateVector(TreeNode *t) {
    int registerName = getNewRegister() printRegister(registerName);
    fprintf(listing, " = %d*4\n", t->child[1]);

    fprintf(listing, "%s = %s[%s]\n", t->child[0]);
}
