#include<stdio.h>

int cauta_subsir (char sir[], char subsir[])
{
    char *s, *p, *q;
    int ok = 0;

    for(s=sir; *s; s++)
        {   p=s;
            q=subsir;
            while ( *q ) /*echivalent cu while (*q != ‘\0’) */
                { if ( *p != *q ) break;
                    p++;
                    q++;
                }
            if ( *q == '\0' ) ok ++;
            }
        return ok;
}

main()
{
    char a[30],b[20];
    printf("Introduceti cuvantul a:");
    gets(a);
    printf("Introduceti cuvantul b:");
    gets(b);
    if(cauta_subsir(a,b)==1) printf("Afirmativ");
    else printf("Negativ");

}
