#include<stdio.h>
#include<string.h>

int verifsufix(char cuv[], char suf[])
{
    int i,j, ok=1;
    int l=strlen(cuv);
    int m=strlen(suf);
    for( i=l-1; i > l-m; i--)
        {
            for(j = m-1; j >= 0; j--)
            if(cuv[i]!=suf[j])
            {ok=0;}
        }
    return ok;
}

int main()
{
    char cuvant[20], sufix[6];
    gets(cuvant);
    gets(sufix);
    printf("%d", verifsufix(cuvant, sufix));
    return(0);
}
