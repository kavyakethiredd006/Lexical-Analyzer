#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

void analyze(FILE *fp, FILE *out)
{
    char ch;
    Token token;
    int i;

    while((ch = fgetc(fp)) != EOF)
    {
        if(isspace(ch))
            continue;

        /* IDENTIFIER OR KEYWORD */
        if(isalpha(ch))
        {
            i = 0;
            token.lexeme[i++] = ch;

            while(isalnum(ch = fgetc(fp)))
                token.lexeme[i++] = ch;

            token.lexeme[i] = '\0';

            if(isKeyword(token.lexeme))
                strcpy(token.type,"Keyword");
            else
                strcpy(token.type,"Identifier");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);

            fseek(fp,-1,SEEK_CUR);
        }

        /* NUMBER (INTEGER OR FLOAT) */
        else if(isdigit(ch))
        {
            int isFloat = 0;
            i = 0;
            token.lexeme[i++] = ch;

            while(isdigit(ch = fgetc(fp)) || ch == '.')
            {
                if(ch == '.')
                    isFloat = 1;

                token.lexeme[i++] = ch;
            }

            token.lexeme[i] = '\0';

            if(isFloat)
                strcpy(token.type,"Floating Constant");
            else
                strcpy(token.type,"Integer Constant");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);

            fseek(fp,-1,SEEK_CUR);
        }

        /* STRING CONSTANT */
        else if(ch == '"')
        {
            i = 0;

            while((ch = fgetc(fp)) != '"')
                token.lexeme[i++] = ch;

            token.lexeme[i] = '\0';

            strcpy(token.type,"String Constant");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);
        }

        /* CHARACTER CONSTANT */
        else if(ch == '\'')
        {
            ch = fgetc(fp);

            token.lexeme[0] = ch;
            token.lexeme[1] = '\0';

            strcpy(token.type,"Character Constant");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);

            fgetc(fp); 
        }

        /* OPERATOR */
        else if(isOperator(ch))
        {
            token.lexeme[0] = ch;
            token.lexeme[1] = '\0';

            strcpy(token.type,"Operator");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);
        }

        /* SPECIAL SYMBOL */
        else if(isSpecialSymbol(ch))
        {
            token.lexeme[0] = ch;
            token.lexeme[1] = '\0';

            strcpy(token.type,"Special Symbol");

            printf("%-20s %-20s\n",token.lexeme,token.type);
            fprintf(out,"%-20s %-20s\n",token.lexeme,token.type);
        }
    }
}