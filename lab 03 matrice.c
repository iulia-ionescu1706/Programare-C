#include<stdio.h>
main()
{
    int m[10][10],aux[10], i, j,k,l,c;
    printf("cititi nr de linii:") ;
    scanf("%d/n",&l);
    printf("cititi nr de coloane:");
    scanf("%d/n", &c);
    printf("cititi elementele matricei:");
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            scanf("%d/n",&m[i][j]);
        }
    }
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            printf("%d ",m[i][j],"/n");

        }
    }
    k=0;
    for(i=0; i<= l-1; i++)
    {
        aux[k]=m[i][0];
        m[i][0]=m[i][1];
        m[i][1]=aux[k];
        k++;
    }
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            printf("%d\n",m[i][j]);
        }
    }

}
