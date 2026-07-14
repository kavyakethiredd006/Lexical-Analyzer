#include <string.h>
#include "lexer.h"

char *keywords[] =
{
"int","float","char","if","else","while","for","return","void","main"
};

int isKeyword(char *word)
{
    for(int i=0;i<10;i++)
    {
        if(strcmp(word,keywords[i])==0)
            return 1;
    }

    return 0;
}

int isOperator(char ch)
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='=');
}

int isRelOperator(char ch)
{
    return(ch=='<'||ch=='>');
}

int isSpecialSymbol(char ch)
{
    return(ch=='('||ch==')'||ch=='{'||ch=='}'||ch==';'||ch==','||ch=='.'||ch=='<'||ch=='>');
}