#include<stdio.h>
int main()
{
    int v[20], i, n, ok , eps = 10e-4;
    double s,med;
    printf("Cu cate numere lucrati?");
      scanf("%d", &n);
      printf("Introduceti numerele:");
      for(i=0; i<= n-1; i++)
      {
          scanf("%d", &v[i]);
      }
      for(i=0; i<= n-1; i++)
      {
          s+= v[i];
      }
      med = (double)s /n;
        ok =0;
      for(i=0; i<= n-1; i++)
      {
            if( abs(v[i] - med ) <= eps ) ok = 1;
            else continue;
      }

      if(ok == 1)
      {
          printf(" Valoarea medie apare in vector. Valoarea medie este %f\n", med);
      }
      else
      {
          printf("Valoarea medie nu apare in vector");
      }
    return 0;

}








