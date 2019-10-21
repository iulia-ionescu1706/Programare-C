#include<stdio.h>
main() /* acest program ajuta la eliminarea zerourilor dintr-un vector*/
{
    int v[21], i, n, j, ok;
    printf("Introduceti un numar de elemente <20:\n");
    scanf("%d", &n);
    printf("Introduceti elementele:");
    for(i =0; i <= n-1; i++)
    {
        scanf("%d/n", &v[i]);
    }
    ok=0;
     for(i =0; i< n; i++)
     {
        if(v[i] ==0 )
        {
            v[i]= v[i+1];
            i= i-1;
            ok ++;
        }
     }
     for(j =0; j< n-ok; j++)
     {
         printf("%d ", v[j]);
    }


}

