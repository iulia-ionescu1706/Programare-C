#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

 typedef struct persoana
 {
     char nume[40];
     char prenume[30];
     float varsta;
 }PERS;

 void citire ()
 {
    FILE *f;
    PERS persoane[5];
    f=fopen("persoane.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    int i;
    for(i=0;i<5;i++)
    {
        printf("Cititi numele persoanei:\n");
        fflush(stdin);
        gets(persoane[i].nume);
        printf("Cititi prenumele persoanei:\n");
        fflush(stdin);
        gets(persoane[i].prenume);
        printf("Cititi varsta persoanei:\n");
        scanf("%f", &persoane[i].varsta);

    }
    PERS *p=persoane;
    for(i=0; i<5; i++)
        fwrite(persoane+i,sizeof(PERS),1,f);
    fclose(f);
 }

 void afisare_fisier(int *n)
 {
     FILE *f;
     PERS persoane[20];
     citire();
     f=fopen("persoane.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }

    int i;
    fseek(f,0L,2);
    *n =ftell(f)/sizeof(PERS);
    fseek(f,0L,0);
    fread(persoane, sizeof(persoane[i]),1,f);
    for(i=0;i < *n;i++)
    {

        printf("%s\t%s\t%f\n", persoane[i].nume, persoane[i].prenume, persoane[i].varsta);
    }
    fclose(f);
 }

 void verificare(PERS persoane[])
 {
     FILE *f;
     float eps =10e-4;
     PERS pnoua;
     int i,gasit=0;
     int n=5;
     f=fopen("persoane.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    printf("Cititi numele, apoi prenumele persoanei cautate:\n");
    gets(pnoua.nume);
    gets(pnoua.prenume);
    printf("Cititi varsta persoanei cautate:\n");
    scanf("%f",&pnoua.varsta);
    while(i!=4 && !gasit)
    {
        fread(persoane,sizeof(persoane[0]),n,f);
        if(strcmp(pnoua.nume, persoane[i].nume)==0&& strcmp(pnoua.prenume, persoane[i].prenume)==0 && abs(pnoua.varsta - persoane[i].varsta)<eps)
        {
            printf("Aceasta persoana deja exista in fisier\n");
            gasit=1;

        }
        i++;
    }
        if(gasit==0)
        {
            printf("Persoana nu exista si se va adauga in fisier\n");
            strcpy(persoane[n].nume, pnoua.nume);
            strcpy(persoane[n].prenume, pnoua.prenume);
            persoane[n].varsta= pnoua.varsta;
            fwrite(persoane,sizeof(persoane[0]),6,f);

        }
    afisare_fisier(&n+1);
    }

 void medie()
 {
    FILE *f;
     PERS persoane[20];
     f=fopen("persoane.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }

    int i,n;
    float s=0.0, ma=0.0;
    fseek(f,0L,2);
    n=ftell(f)/sizeof(PERS);
    fseek(f,0L,0);
    fread(persoane,sizeof(persoane[0]),n,f);
        for(i=0; i< n; i++)
        {
            s += persoane[i].varsta;
        }
   ma = s/n;
   printf("Media de varsta a persoanelor din evidenta este %f\n", ma);

 }
 void eliminare_pers(char nume[])
 {
    FILE *f, *ftmp;
    int i, n, gasit=0;
     PERS persoane[20];
     f=fopen("persoane.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    ftmp=fopen("persoane_temp.dat","wb");
    if(ftmp==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    printf("Cititi numele persoanei pe care doriti sa o eliminati:\n");
    gets(nume);
    fseek(f,0L,2);
    n=ftell(f)/sizeof(PERS);
    fseek(f,0L,0);
    fread(persoane,sizeof(persoane[0]),1,f);
    for(i=0; i<n; i++)
    {
        if(strcmp(persoane[i].nume, nume)==0)
        {
            printf("O persoana cu acest nume a fost gasita si va fi scoasa din evidenta\n");
            gasit =1;
        }
       else fwrite(&persoane[i],sizeof(persoane[i]),1,ftmp);
    }
    if(gasit==0)
        printf("Persoana cu acest nume nu a fost gasita\n");
    fclose(f);
    fclose(ftmp);
    remove("persoane.dat");
    rename("persoane_temp.dat", "persoane.dat");

 }
 void verif_pers_3(FILE *f)
 {
    int i,n, corect=0;
    char c;
    char numenou[30];
     PERS persoane[20];
     f=fopen("persoane.dat","a+b");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(PERS);
    fseek(f,0L,0);
    fread(persoane,sizeof(persoane[0]),n,f);
    printf("Acesta este numele actual din fisier al persoanei a treia:\n");
    fputs(persoane[2].nume,f);
    do
    {
    printf("Doriti sa modificati numele?(d/n)\n");
    scanf("%c",&c);
    switch(c)
    {
        case 'd':   corect =1;
                    printf("Introduceti noul nume, corect:");
                    gets(numenou);
                    fseek(f, 2*(sizeof(persoane[i])),0);
                    //strcpy(persoane[2].nume," ");
                    strcpy(persoane[2].nume, numenou);
                    fwrite(&persoane[2].nume, sizeof(persoane[2].nume),1,f);
                    break;
        case 'n':   corect =1;
                    exit(0);
        default:    printf("Ati introdus o litera diferita de d/n, reintroduceti:\n");

    }
    }while(corect==0);
 }



 main()
 {
    FILE *f;
    PERS persoane[10];
    int optiune,n;
    char nume[30];
    printf("Ce functie doriti sa apelati?\n Tastati:\n 1 - pentru citire de informatii in fisier;\n");
    printf("2 - pentru afisarea continutului fisierului;\n ");
    printf("3 - pentru verificarea existentei unei persoane in evidenta;\n");
    printf("4 - pentru calculul si afisarea mediei de varsta a tuturor persoanelor din fisier;\n");
    printf("5 - pentru eliminarea din fisier a unor persoane cu anumite nume; \n");
    printf("6 - pentru verificarea corectitudinii numelui celei de-a treia persoane;\n");
    printf("Tastati optiunea dvs:\n");
    scanf("%d", &optiune);
    switch(optiune)
    {
        case 1:     citire(); break;
        case 2:     afisare_fisier(&n); break;
        case 3:     verificare(persoane); break;
        case 4:     medie(); break;
        case 5:     eliminare_pers(nume); break;
        case 6:     verif_pers_3(f); break;
        default:    printf("Nu ati tastat un numar cuprins intre 1 si 6, incercati din nou!");
    }




 }
