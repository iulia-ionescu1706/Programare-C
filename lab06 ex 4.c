#include<stdio.h>
 void comune(int v1[], int v2[], int n, int m)
 {
     int i, j, v3[30], k = 0, ok =0;
     for(i = 0; i <= n; i ++)
     {
         for( j = 0; j <= m; j ++)
         {
             if (v1[i] == v2[j])
                {
                    ok =1;
                    v3[k++] = v1[i];
                }

         }
     }
     if (ok == 1)
        for(i = 0; i <= k -1; k++ )
     {
         printf("%d ", v3[k]);
     }
     else printf("Nu sunt elemente comune");
 }

 main()
 {
     int v[30], w[30], n,i, j, m;
     printf("Cate elemente are primul vector?");
     scanf("%d", &n);
     printf("Cate elemente are al doilea vector?");
     scanf("%d", &m);
     printf("Introduceti elementele primului vector:");
     for(i= 0; i <= n-1; i++)
        scanf("%d", &v[i]);
     printf("Introduceti elementele celui de-al doilea vector:");
     for(j= 0; j <= m-1; j++)
        scanf("%d", &w[i]);
     comune(v, w, n, m);

 }
