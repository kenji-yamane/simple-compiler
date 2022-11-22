/****************************************************/
/* File: analyze.h                                  */
/* Semantic analyzer interface for C- compiler      */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include "globals.h"

/* Procedure analyze performs type checking
 * and other semantic analysis of the syntax tree
 */
void analyze(TreeNode *);

#endif
