/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the C- compiler       */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

/* the list of line numbers of the source
 * code in which a variable is referenced
 */
struct LineListRec {
    int lineno;
    struct LineListRec *next;
};
typedef struct LineListRec LineListRec;
typedef LineListRec *LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
struct BucketListRec {
    char *name;
    int scope;
    ExpType type;
    DeclKind kind;
    LineList lines;
    struct BucketListRec *next;
};

typedef struct BucketListRec BucketListRec;
typedef BucketListRec *BucketList;

bool equalRecs(BucketListRec *l, char *name, int scope);

BucketListRec *st_insert(char *name, int lineno, int scope, ExpType type,
                         DeclKind kind);

BucketList st_lookup(char *name, int scope);

void st_remove(int scope);

void removeNext(BucketListRec *l);

BucketListRec *removeHead(BucketListRec *head);

void freeRec(BucketListRec *l);

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE *listing);

#endif
