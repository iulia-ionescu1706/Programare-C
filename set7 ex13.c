#include<stdio.h>
#include<string.h>

void stergere(char sir[], int n, int p)
{
    int i;
    int l= strlen(sir);
    for(i =p; i<=p+n; i++)
        sir[i]= sir[i+1];
        i--;
}
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

void inserare(char sir[], char s[], int q)
{
    int i,j;
    int l= strlen(sir);
    int m = strlen(s);
    for(i=q; i<= l-m-q; i++)
    for(j=0; j<= m-1; j++)
        sir[i++]= s[j];

}

main()
{
    char sir[30], s[10];
    gets(sir);
    int p;
    gets(s);
    p= cauta_subsir(sir,s);
    stergere(sir,s,p);
    inserare(sir,s,p);




}
