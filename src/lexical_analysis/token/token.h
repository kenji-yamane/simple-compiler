#ifndef _TOKEN_H_
#define _TOKEN_H_

typedef enum {
    /* book-keeping tokens */
    ENDFILE,ERROR,
    /* reserved words */
    IF,THEN,ELSE,END,REPEAT,UNTIL,READ,WRITE,
    /* multicharacter tokens */
    ID,NUM,
    /* special symbols */
    ASSIGN,EQ,LT,PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI
} TokenType;

typedef struct {
	int line;
	TokenType type;
	char *lexeme;
	int lexeme_size;
} Token;

Token newToken();

Token appendChar();

void deleteToken();

#endif

