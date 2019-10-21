#include<stdio.h>
int main()
{
int v[15], ok , i, n, aux = 0, trecere = 0;
      printf("Cu cate numere lucrati?");
      scanf("%d", &n);
      printf("Introduceti numerele:");
      for(i=0; i<= n-1; i++)
      {
          scanf("%d", &v[i]);
      }

      do
      {
        ok =0;
        trecere +=1;
        for(i=0; i< n-trecere; i++)

          {
              if(v[i]< v[i+1])
          {
              aux = v[i];
              v[i]= v[i+1];
              v[i+1]= aux;
              ok = 1;
          }
          }
      } while (ok);

      for(i=0; i<= n-1; i++)
      {
          scanf("Vectorul ordonat:%d ", v[i]);
      }
      return 0;
}
