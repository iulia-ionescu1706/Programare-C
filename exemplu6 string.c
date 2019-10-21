#include<stdio.h>
#include<string.h>
#include<conio.h>

int separare(char* txt, char* p)
{
	int k=0;
	p=strtok(txt," ");
	while (p!=NULL)
	{
		p=strtok(NULL, " ");
		k++;
	}
	return k;
}
void main()
{
	int k;
	char txt[1024]; //sir introdus de utilizator
	char p;
	printf("Introduceti un sir de caractere si apoi apasati Enter\n");
	gets(txt); //scanf("%s",&txt);

	printf("\nNumarul de cuvinte este: %d",separare(txt,&p)); //nu se numara caracterul NULL

	getch();
}
