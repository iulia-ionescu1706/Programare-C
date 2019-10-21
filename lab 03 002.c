#include<stdio.h>
main()
{
    int v[21],par[21], imp[21], i, n, j,k, pare=0, impare=0;
    printf("Introduceti un numar de elemente <20:\n");
    scanf("%d", &n);
    printf("Introduceti elementele:");
    for(i =0; i <= n-1; i++)
    {
        scanf("%d/n", &v[i]);
    }

    for(i =0; i <= n-1; i++)
    {
        if (v[i]%2 == 0)
        {
            par[k++]=v[i];
            pare++;
        }
        else
        {
            imp[j++]=v[i];
            impare++;
        }

    }
    printf("Pare:");
    for(k =0; k <= pare-1; k++)
        printf("%d ", par[k]);
        printf("\n");
    for(j=0; j <= impare-1; j++)
        printf("%d ", imp[j]);

}
