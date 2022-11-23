#include "generator.h"

int rCnt = 0;
int getNewRegister() { return rCnt++; }
void printRegister(int r) { fprintf(listing, "r%d", r); }

int labelCnt = 0;
int getNewLabel() { return labelCnt++; }
void printLabel(int l) { fprintf(listing, "l%d", l); }

void printSpaces(int spaces) {
	for (int i = 0; i < spaces; i++) {
		fprintf(listing, " ");
	}
}

void printChar(char c) { fprintf(listing, "%c", c); }

void generateCode(TreeNode *root, int spaces) {
	printSpaces(spaces);
	fprintf(listing, "goto main\n");
	generateSequentials(root, spaces);
}

void generateSequentials(TreeNode *t, int spaces) {
	if (t == NULL) {
		return;
	}
	TreeNode *seq = t;
	while (seq != NULL) {
		generateTree(seq, spaces);
		seq = seq->sibling;
	}
}

void generateTree(TreeNode *t, int spaces) {
    if (t == NULL) {
        return;
    }
    switch (t->nodekind) {
    case StmtK:
		generateStatement(t, spaces);
        break;
    case ExpK:
		generateExpression(t, spaces, -1);
        break;
    case DeclK:
		generateDeclaration(t, spaces);
        break;
    }
}

void generateStatement(TreeNode *t, int spaces) {
    if (t == NULL) {
        return;
    }
	int aux, label1, label2;
    switch (t->kind.exp) {
    case IfK:
		aux = getNewRegister();
		generateExpression(t->child[0], spaces, aux);
		printSpaces(spaces);
		fprintf(listing, "if_false ");
		printRegister(aux);
		fprintf(listing, " goto ");
		label1 = getNewLabel();
		printLabel(label1);
		printChar('\n');

		generateSequentials(t->child[1], spaces);
		printLabel(label1);
		fprintf(listing, ":\n");
		if (t->child[2] != NULL) {
			generateSequentials(t->child[2], spaces);
		}
        break;
    case RepeatK:
		label1 = getNewLabel();
		label2 = getNewLabel();
		printLabel(label1);
		fprintf(listing, ":\n");
		aux = getNewRegister();
		generateExpression(t->child[0], spaces, aux);
		printSpaces(spaces);
		fprintf(listing, "if_false ");
		printRegister(aux);
		fprintf(listing, " goto ");
		printLabel(label2);
		printChar('\n');
		generateSequentials(t->child[1], spaces);
		printSpaces(spaces);
		fprintf(listing, "goto ");
		printLabel(label1);
		printChar('\n');
		printLabel(label2);
		fprintf(listing, ":\n");
        break;
    case AssignK:
		aux = getNewRegister();
		generateExpression(t->child[1], spaces, aux);
		generateVariableForAssignment(t->child[0], spaces);
		fprintf(listing, " = ");
		printRegister(aux);
		printChar('\n');
        break;
    case ReturnK:
		if (t->child[0] != NULL) {
			aux = getNewRegister();
			generateExpression(t->child[0], spaces, aux);
			printSpaces(spaces);
			fprintf(listing, "return ");
			printRegister(aux);
			printChar('\n');
		} else {
			printSpaces(spaces);
			fprintf(listing, "return\n");
		}
        break;
    }
}

void generateExpression(TreeNode *t, int spaces, int finalRegister) {
    if (t == NULL) {
        return;
    }
	int left, right, aux;
    switch (t->kind.exp) {
    case OpK:
        left = getNewRegister(); right = getNewRegister();
        generateExpression(t->child[0], spaces, left);
        generateExpression(t->child[1], spaces, right);
		printSpaces(spaces);
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
		printSpaces(spaces);
        printRegister(finalRegister);
        fprintf(listing, " = ");
        fprintf(listing, "%d\n", t->attr.val);
        break;
    case IdK:
		aux = getNewRegister();
		generateVariable(t, spaces, aux);
		printSpaces(spaces);
		if (finalRegister != -1) {
			printRegister(finalRegister);
			fprintf(listing, " = ");
			printRegister(aux);
		}
		printChar('\n');
		break;
    }
}

void generateVariableForAssignment(TreeNode *t, int spaces) {
	if (t == NULL) {
		return;
	}
	int idx;
	switch (t->declType) {
	case VarK:
		printSpaces(spaces);
		fprintf(listing, "%s", t->attr.name);
		break;
	case VecK:
		idx = getNewRegister();
		generateExpression(t->child[0], spaces, idx);
		printSpaces(spaces);
		fprintf(listing, "%s[", t->attr.name);
		printRegister(idx);
		fprintf(listing, "]");
		break;
	case FunK:
		fprintf(listing, "Error while generating code: assignment to function not possible\n");
		break;
	}
}

void generateVariable(TreeNode *t, int spaces, int finalRegister) {
	if (t == NULL) {
		return;
	}
	int idx, paramsCount, paramsRegister;
	switch (t->declType) {
	case VarK:
		printSpaces(spaces);
		printRegister(finalRegister);
		fprintf(listing, " = %s\n", t->attr.name);
		break;
	case VecK:
		idx = getNewRegister();
		generateExpression(t->child[0], spaces, idx);
		printSpaces(spaces);
		printRegister(finalRegister);
		fprintf(listing, " = %s[", t->attr.name);
		printRegister(idx);
		fprintf(listing, "]\n");
		break;
	case FunK:
		paramsCount = 0;
		TreeNode *paramNode = t->child[0];
		while (paramNode != NULL) {
			paramsCount++;
			paramsRegister = getNewRegister();
			generateExpression(paramNode, spaces, paramsRegister);
			printSpaces(spaces);
			fprintf(listing, "param ");
			printRegister(paramsRegister);
			printChar('\n');
			paramNode = paramNode->sibling;
		}
		printSpaces(spaces);
		BucketListRec *funcRec = st_lookup(t->attr.name, 0);
		if (funcRec->type == Integer) {
			printRegister(finalRegister);
			fprintf(listing, " = ");
		}
		fprintf(listing, "call %s, %d\n", t->attr.name, paramsCount);
		break;
	}
}

void generateDeclaration(TreeNode *t, int spaces) {
    if (t == NULL) {
        return;
    }
    switch (t->kind.decl) {
    case VarK:
    case VecK:
		break;
    case FunK:
		printSpaces(spaces);
		fprintf(listing, "%s:\n", t->child[0]->attr.name);
		spaces += 4;
		generateSequentials(t->child[0]->child[1], spaces);
        break;
    }
}

