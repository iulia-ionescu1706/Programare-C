#include<stdlib.h>
#include<string.h>
#include<stdio.h>
main()
{
    FILE *fisiertext;
    FILE *fisierbinar;

    int v[30],n,i;
    if((fisiertext=fopen("exemplutext.txt","wt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis\n");
        exit(1);
    }
    if((fisierbinar=fopen("exemplubinar.txt","wb"))==NULL)
    {
        puts("Fisierul nu poate fi deschis\n");
        exit(1);
    }
    printf("Introduceti dimensiunea tabloului:");
    scanf("%d",&n);
    printf("Tastati valori de la tastatura pentru fiecare element al tabloului:");
    for(i=0; i<n; i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }

    fprintf(fisiertext,"%d",v);
    fwrite(v,sizeof(v[0]),n,fisierbinar);

    fread(v,sizeof(v[0]),n,fisierbinar);


    fclose(fisiertext);
    fclose(fisierbinar);





}
