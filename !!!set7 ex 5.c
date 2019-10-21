#include<stdio.h>
#include<string.h>

void eliminarelitera(char s[], int poz)
{
    int i,j, l;
    l = strlen(s);
    for(i = 0; i < l; i++)
    {
        if(i == poz)
        {
            for(j = i+1; j<= l-1; j++)
            {
                s[j]= s[j+1];
                l--;
                j--;
            }
        }

    }

}

void cuvinte(char s[])
{
    int i,l;
    l = strlen(s);
    for(i=0; i<= l-1; i++)
    {
       eliminarelitera(s,i);
        puts(s);
        printf("\n");
    }
}

main()
{
    char s[30];
    scanf("%s", s);
    cuvinte(s);
}
