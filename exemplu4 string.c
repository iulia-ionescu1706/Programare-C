#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
	char* a; //sir introdus de utilizator
	int i; //indexul sirului

	a=(char*)malloc(sizeof(char)*255) ;

	printf("Introduceti un sir de caractere si apoi apasati Enter\n");
	gets(a); //scanf("%s",&a);

	//Afiseaza fiecare caracter pana cand gaseste pe NULL
	for(i=0; a[i]!=NULL;i++)
	putchar(a[i]);
	//sau printf("%c",a[i]);
	printf("\nNumarul de caractere este %d adica %d",i,strlen(a)); //nu se numara caracterul NULL

	//doresc sa introduc un nou sir de caractere
	char b[]=" alt sir";
	strcat(a,b); //adaug sirul de adresa b la sirul a (realizez concatenarea celor doua)
	printf("\nNoul sir a este \"%s\"",a); // sau puts("Noul sir a este"); puts(a);
	strcpy(b,a); //copiaza sirul a in b
	puts("\nNoul sir b este:");
	puts(b);

	//se compara cele doua siruri
	printf("%d",strcmp(a,b));

	getch();
}
