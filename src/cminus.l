%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
%}
digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+
%%
"if"            {return IF;}
"else"          {return ELSE;}
"while"         {return WHILE;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"<"             {return LT;}
"<="            {return LTEQ;}
">"             {return GT;}
">="            {return GTEQ;}
"=="            {return EQ;}
"!="            {return NEQ;}
"="             {return ASSIGN;}
";"             {return SEMI;}
","             {return COMMA;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LBRACK;}
"]"             {return RBRACK;}
"{"             {return LBRACE;}
"}"             {return RBRACE;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {
					lineno++;
					if (TraceScan) {
			            fprintf(listing, "line %d:\n", lineno);
			        }
				}
{whitespace}    {/* skip whitespace */}
"/*"            {
					char c = 'a', last;
					do {
						last = c;
					    c = input();
					    if (c == YY_NULL)
					        break;
					    if (c == '\n')
					        lineno++;
					} while (!(last == '*' && c == '/'));
                }
.               {return ERROR;}
%%
TokenType getToken(void) {
    static int firstTime = TRUE;
    TokenType currentToken;
    if (firstTime) {
        firstTime = FALSE;
        lineno++;
		if (TraceScan) {
            fprintf(listing, "line %d:\n", lineno);
		}
        yyin = source;
        yyout = listing;
    }
    currentToken = yylex();
    strncpy(tokenString, yytext, MAXTOKENLEN);
    if (TraceScan) {
        printToken(currentToken, tokenString);
    }
    return currentToken;
}
