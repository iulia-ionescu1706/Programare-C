#include<stdio.h>
/* Scrieti un program care citeşte un şir de numere întregi de la tastatură şi verifică dacă acesta este ordonat
 crescător, descrescător, este constant sau nu este ordonat. Se va afişa un mesaj corespunzator: "crescător ",
  "descrescător”, “constant” sau “oarecare”.*/

  int main()
  {
      int v[15], ok = 0,dc = 0, i, n,egal = 0;
      printf("Cu cate numere lucrati?");
      scanf("%d", &n);
      printf("Introduceti numerele:");
      for(i=0; i<= n-1; i++)
      {
          scanf("%d", &v[i]);
      }
      for(i=0; i<= n-2; i++)
      {
            if(v[i]< v[i+1]) ok++;
      }
      for(i=0; i<= n-2; i++)

      {
          if(v[i]> v[i+1]) dc ++;
        }
      for(i=0; i<= n-2; i++)
      {
          if (v[i] == v[i+1]) egal++;
      }

      if (dc == n-1 && (ok ==0 && egal == 0))
      {
          printf("Sir descrescator");
      }
      else;

        if (ok == n-1 &&(dc ==0 && egal == 0) )
        {
            printf("Sir crescator");
        }
        else;
        if(egal== n-1 && (ok ==0 && dc ==0))
        {
            printf("Sir constant");
        }
        else;

        if(ok != 0 && dc != 0 && egal != 0)
        printf("Sir oarecare");

    return 0;
    }









