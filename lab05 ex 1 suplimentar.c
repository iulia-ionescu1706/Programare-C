#include<stdio.h>
 int fibo(int n)
 {
     int i,j,v[100];
     int* p;
     v[0] = 1;
     v[1] = 1;
     for(i=2; i<= n-1; i++)
     {
         v[i] = v[i-1] + v[i-2];
     }
     p = &v[n-1];
     return *p;
 }

 int factorial(int n)
 {
     int i;
     int pr=1;
     int* p;
     p = &pr;
     for(i=1; i<=n; i++)
     {
         pr *= i;
     }

     return *p;
 }
 double expresie(int n)
 {
     return((float)fibo(n)/factorial(n));
 }
 main()
 {
     int n;
     printf("Introduceti un numar int:");
     scanf("%d", &n);
     printf("%d\n", fibo(n));
     printf("%d\n", factorial(n));
     printf("%f", expresie(n));
 }
