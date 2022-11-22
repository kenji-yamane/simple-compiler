/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the C- compiler  */
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "symtab.h"
#include <stdlib.h>
#include <string.h>

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash(char *key) {
    // printf(">>>> key: %s\n", key);
    int temp = 0;
    int i = 0;
    while (key[i] != '\0') {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

bool equalRecs(BucketListRec *l, char *name, int scope) {
    if (strcmp(l->name, name) != 0) {
        return false;
    }
    if (l->scope != scope) {
        return false;
    }
    return true;
}

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts an identifier
 * into the symbol table. If the identifier
 * was already in the symbol table, it
 * adds a new line
 */
BucketListRec *st_insert(char *name, int lineno, int scope, ExpType type,
                         DeclKind kind) {
    // printf("!\n");
    int h = hash(name);
    // printf(")\n");
    BucketList l = hashTable[h];
    while (l != NULL && !equalRecs(l, name, scope))
        l = l->next;
    // printf("#\n");
    if (l != NULL) { /* found in table, so just add line number */
        LineListRec *t = l->lines;
        while (t->next != NULL)
            t = t->next;
        t->next = (LineListRec *)malloc(sizeof(LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
    // printf("&\n");
    /* variable not yet in table, so we'll add it */
    l = (BucketListRec *)malloc(sizeof(BucketListRec));
    l->name = name;
    l->lines = (LineListRec *)malloc(sizeof(LineListRec));
    l->lines->lineno = lineno;
    l->type = type;
    l->scope = scope;
    l->kind = kind;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l;
    // printf("@\n");
    return l;
} /* st_insert */

/* Function st_lookup returns if a given variable
 * already exists in the table
 */
BucketList st_lookup(char *name, int scope) {
    // printf("> lookup: %s\n", name);
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && !equalRecs(l, name, scope))
        l = l->next;
    // printf("ok! %d\n", (int) l);
    return l;
}

/* Function st_remove removes every variable
 * that has the given scope
 */
void st_remove(int scope) {
    for (int i = 0; i < SIZE; i++) {
        BucketList l = hashTable[i], head = l;
        while (l != NULL && l->scope == scope) {
            l = removeHead(l);
        }
        while (l != NULL && l->next != NULL) {
            if (l->next->scope == scope) {
                removeNext(l);
            } else {
                l = l->next;
            }
        }
    }
}

/* Function removeNext
 * removes the node after l
 */
void removeNext(BucketListRec *l) {
    BucketListRec *nextNext = l->next->next;
    freeRec(l->next);
    l->next = nextNext;
}

/* Function removeHead
 * removes the head of a linked list
 * returning the new head
 */
BucketListRec *removeHead(BucketListRec *head) {
    BucketListRec *prev = head;
    head = head->next;
    freeRec(prev);
    return head;
}

/* Function freeRec frees
 * memory associated with rec
 */
void freeRec(BucketListRec *l) {
    LineList t = l->lines, prev = NULL;
    while (t != NULL) {
        prev = t;
        t = t->next;
        free(prev);
    }
    free(l);
}

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void printSymTab(FILE *listing) {
    int i;
    fprintf(listing, "Variable Name   Line Numbers\n");
    fprintf(listing, "-------------   ------------\n");
    for (i = 0; i < SIZE; ++i) {
        if (hashTable[i] != NULL) {
            BucketList l = hashTable[i];
            while (l != NULL) {
                LineList t = l->lines;
                fprintf(listing, "%-14s ", l->name);
                while (t != NULL) {
                    fprintf(listing, "%4d ", t->lineno);
                    t = t->next;
                }
                fprintf(listing, "\n");
                l = l->next;
            }
        }
    }
} /* printSymTab */
