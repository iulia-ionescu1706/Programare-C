#include<stdio.h>
#include<string.h>
#include<conio.h>


 int cauta_subsir(char* a, char* b)
    {
        int nr;
        char *s, *p, *q;
        for(s= a; *s; s++)
        {
            p = s;
            q = b;
            while(*q)
            {
                if(*p != *q) break;
                p ++;
                q ++;

            }
            nr ++;
            //if(*q =='\0') return (s- a);
        }
        if (nr ==1)return 1;
       else return 0;
    }


main()
{
    char a[20], b[20];
    gets(a);
    gets(b);
    printf("%d", cauta_subsir(a,b));
}
