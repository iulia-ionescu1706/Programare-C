#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

/* Exista aplicatii in care este necesar sa se lucreze cu n cuvinte – intelegand prin caracter
o succesiune de caractere care nu sunt albe. In acest caz avem posibilitatea sa declaram vectori
de cuvinte. Acestea sunt, de fapt, matrice cu elemente de baza de tip char. */

void main()
{
char cuvinte[10][25];	/* fiecare linie din cele 10 ale matricei poate retine un sir de tipul char*.
				Acesta poate avea cel mult 25 de caractere (inclusiv caracterul nul).
		Cuvintele pot fi adresate prin a[0] (primul cuvant), a[1] (cuvantul al doilea) etc*/
	char aux[];
	int i,n,gasit;
	printf("Dati numarul de cuvinte: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("cuvant: ");
		scanf("%s",&cuvinte[i]);
	}
	do
	{
		gasit=0;
		for(i=0;i<n-1;i++)
			if ( strcmp(cuvinte[i],cuvinte[i+1]) > 0 )
			{
				strcpy(aux,cuvinte[i]);
				strcpy(cuvinte[i],cuvinte[i+1]);
				strcpy(cuvinte[i+1],aux);
				gasit=1;
			}
	} while (gasit);
	for(i=0;i<n;i++)
	printf("\n%s",cuvinte[i]);
	getch();

}
