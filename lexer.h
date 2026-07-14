#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

typedef struct
{
    char lexeme[100];
    char type[50];
} Token;

void analyze(FILE *fp, FILE *out);

int isKeyword(char *word);
int isOperator(char ch);
int isRelOperator(char ch);
int isSpecialSymbol(char ch);

#endif