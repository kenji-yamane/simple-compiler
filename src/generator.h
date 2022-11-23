#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include "globals.h"
#include "symtab.h"
#include "util.h"

int getNewRegister();
void printRegister(int r);

int getNewLabel();
void printLabel(int l);

void printSpaces(int spaces);
void printChar(char c);

void generateCode(TreeNode *root, int spaces);
void generateSequentials(TreeNode *t, int spaces);
void generateTree(TreeNode *t, int spaces);
void generateStatement(TreeNode *t, int spaces);
void generateExpression(TreeNode *t, int spaces, int finalRegister);
void generateVariableForAssignment(TreeNode *t, int spaces);
void generateVariable(TreeNode *t, int spaces, int finalRegister);
void generateDeclaration(TreeNode *t, int spaces);

#endif

