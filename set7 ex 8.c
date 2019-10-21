#include<stdio.h>
#include<string.h>

int cauta_subsir (char * sir, char * subsir)
{
    char *s, *p, *q;

    for(s=sir; *s; s++)
        {   p=s;
            q=subsir;
            while ( *q ) /*echivalent cu while (*q != ‘\0’) */
                { if ( *p != *q ) break;
                    p++;
                    q++;
                }
            if ( *q == '\0' ) return (s-sir);
            }
        return -1;
}
int verifsufix(char cuv[], char suf[])
{
    int l=strlen(cuv);
    int m=strlen(suf);
    int ok=1;

    if(cauta_subsir(cuv, suf)!= (l-m)) ok=0;
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
