#include<stdio.h>
 int identic(int v[],int w[], int n, int m)
 {
     int i, ok =1;
     if(n != m) ok = 0;
     else
     {
         for(i= 0; i<= n-2; i++)
     {
         if (v[i] != w[i])
         {
             ok =0;
             break;
         }
     }
     }
     return ok;
 }
 main()
 {
     int m[6][6], l, c,i ,j;
     printf("Cate linii are matricea?");
     scanf("%d", &l);
     printf("Cate coloane are matricea?");
     scanf("%d", &c);
     printf("Cititi elementele matricei:");
     for(i =0; i<= l-1; i++)
     {
         for(j= 0; j<= c- 1; j++)
            scanf("%d", &m[i][j]);
     }
     for(i=0; i<= l-1; i++)
     {
         for(j=0; j <= c -1; j++)
            identic(m[i], m[j], l, c);
     }


}
