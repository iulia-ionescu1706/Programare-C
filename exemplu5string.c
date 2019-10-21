#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
	int k=0;
	char txt[1024]; //sir introdus de utilizator
	char* p;
 	printf("Introduceti un sir de caractere si apoi apasati Enter\n");
	gets(txt); //scanf("%s",&txt);

	p=strtok(txt," ");
		while (p!=NULL)
	{
		p=strtok(NULL, " ");
		k++;
	}
	printf("\nNumarul de cuvinte este: %d",k); //nu se numara caracterul NULL

	getch();
}
