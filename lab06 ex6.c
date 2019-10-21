#include<stdio.h>
void elim(int *v[20], int *n)
{
    int i, *nr;

    for(i= 1; i<= *n-1; i++)
    {
        if (v[i] == v[0])
            {
                v[i] = v[i+1];
                    i--;
                    nr ++;
            }
    }

}
main()
{
    int v[20],n, i, nr;
    printf("Citeste nr. de elemente din vector:");
    scanf("%d", &n);
    printf("Citeste elementele vectorului:");
    for(i = 0; i <= n -1; n++ )
    {
        scanf("%d ", &v[i]);
    }
    elim(v,n);
    for(i = 0; i <= &nr; i ++)
    {
         printf("%d ", v[i]);
    }

}
