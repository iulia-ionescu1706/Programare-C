#include<stdio.h>

/*Ionescu Iulia 313AC*/
 void nrpare(int nr, int *nrpar)
 {
    *nrpar = 0;
    while(nr)
     {
         if ((nr% 10) %2 == 0)
         {
             (*nrpar) += (nr % 10);
              (*nrpar) = (*nrpar)*10;

         }
        nr /= 10;
     }

     printf("Numarul din cifre pare obtinut este:%d\n", *nrpar);

 }
 main()
 {
     int nr;
     int nrpar ;
     printf("Citeste nr de la tastatura:");
     scanf("%d", &nr);
     nrpare(nr, &nrpar);

    getch();

 }
