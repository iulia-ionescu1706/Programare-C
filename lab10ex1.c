#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fisier;
    char c;
    long l;
    int k,i;
    char alineat='\n';
    char *p;
    char sir[200];
    fisier=fopen("exemplu.txt","wt");
    if(fisier/*=fopen("exemplu.txt","wt"))*/==NULL)
    {
        puts("Fisierul nu poate fi deschis\n");
        exit(1);
    }
    puts("Tastati o fraza care se incheie cu punct:\n");

    /*Scriere in fisier caracter cu caracter*/
    do
    {
        c=getchar();
    putc(c,fisier);
    }while(c!='.');

    /*Scrierea frazei cu totul:*/
    gets(sir);
    fputs(sir,fisier);

    /*Scrierea cuvant cu cuvant,pe linii diferite:*/

	p=strtok(sir," ");
	while (p!=NULL)
	{
		fputs(p,fisier);
		fputs("\n",fisier);
		p=strtok(NULL, " ");
		k++;
	}

	/*Scrierea cuvant cu cuvant,pe o singura linie :*/

	p=strtok(sir," ");
	while (p!=NULL)
	{
		fputs(p,fisier);
		p=strtok(NULL, " ");
		k++;
	}

	/*Afisare caracter cu caracter:*/
	l=strlen(sir);
	for(i=0;i<=l-1;i++)
	{fread(sir,sizeof(sir[0]),l,fisier);
	printf("%c",sir[i]);
	}

    /*Afiarea intregii linii:*/
    fputs(sir,fisier);

    fclose(fisier);
}
