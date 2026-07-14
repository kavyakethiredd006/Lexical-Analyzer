#include <stdio.h>
#include "lexer.h"

int main()
{
    FILE *fp;
    FILE *out;

    fp = fopen("program.c","r");
    out = fopen("tokens.txt","w");

    if(fp == NULL)
    {
        printf("Input file not found\n");
        return 0;
    }

    printf("\nTokens Generated:\n\n");
    printf("%-20s\t%-20s\n","LEXEME","TOKEN TYPE");
    printf("----------------------------------------\n");

    fprintf(out,"%-20s\t%-20s\n","LEXEME","TOKEN TYPE");
    fprintf(out,"----------------------------------------\n");

    analyze(fp,out);

    fclose(fp);
    fclose(out);

    printf("\nTokens also saved in tokens.txt\n");

    return 0;
}