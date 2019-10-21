#include<stdio.h>
#include<string.h>
typedef struct persoana
{
    char nume[25];
    char prenume[25];
    char CNP[13];
};


main()
{
    struct persoana persoane[10];
    int n,i,j;
    struct persoana aux;
    int ok =0;
    printf("Introduceti nr de persoane:");
    scanf("%d", &n);
    for(i=0; i<= n-1; i++)
     {
        printf("Citeste datele despre persoana %d:",i+1);
        printf("Citeste numele persoanei:");
        scanf("%s", &persoane[i].nume);
        printf("Citeste prenumele persoanei:");
        scanf("%s", &persoane[i].prenume);
        printf("Citeste CNP-ul persoanei:");
        scanf("%s", &persoane[i].CNP);
     }

    for(i=0; i<= n-1; i++)
    {
        fflush(stdin);
        puts(persoane[i].nume);
         printf("\n");
         fflush(stdin);
        puts(persoane[i].prenume);
        printf("\n");
        fflush(stdin);
        puts(persoane[i].CNP);
        printf("\n");
        fflush(stdin);
    }

    do
    {
        ok=1;
        for(i=0; i< n-1; i++)
        {
            if(strcmp(persoane[i].nume, persoane[i+1].nume) >0)
            {
                strcpy(aux.nume, persoane[i].nume);
                strcpy(persoane[i].nume, persoane[i+1].nume);
                strcpy(persoane[i+1].nume, aux.nume);

                strcpy(aux.prenume, persoane[i].prenume);
                strcpy(persoane[i].prenume, persoane[i+1].prenume);
                strcpy(persoane[i+1].prenume, aux.prenume);

                strcpy(aux.CNP, persoane[i].CNP);
                strcpy(persoane[i].CNP, persoane[i+1].CNP);
                strcpy(persoane[i+1].CNP, aux.CNP);

                ok=0;
            }
        }
    } while (ok ==0);


    do
    {
        ok=1;
        for(i=0; i< n-1; i++)
        {
            if(strcmp(persoane[i].prenume, persoane[i+1].prenume) >0)
            {
                strcpy(aux.prenume, persoane[i].prenume);
                strcpy(persoane[i].prenume, persoane[i+1].prenume);
                strcpy(persoane[i+1].prenume, aux.prenume);

                strcpy(aux.nume, persoane[i].nume);
                strcpy(persoane[i].nume, persoane[i+1].nume);
                strcpy(persoane[i+1].nume, aux.nume);

                strcpy(aux.CNP, persoane[i].CNP);
                strcpy(persoane[i].CNP, persoane[i+1].CNP);
                strcpy(persoane[i+1].CNP, aux.CNP);

                ok=0;
            }
        }
    } while (ok ==0);


    do
    {
        ok=1;
        for(i=0; i< n-1; i++)
        {
            for(j=1; j<=6; j++)
            {
                if( persoane[i].CNP[j]> persoane[i+1].CNP[j])
                {
                    strcpy(aux.nume, persoane[i].nume);
                    strcpy(persoane[i].nume, persoane[i+1].nume);
                    strcpy(persoane[i+1].nume, aux.nume);

                    strcpy(aux.prenume, persoane[i].prenume);
                    strcpy(persoane[i].prenume, persoane[i+1].prenume);
                    strcpy(persoane[i+1].prenume, aux.prenume);

                    strcpy(aux.CNP, persoane[i].CNP);
                    strcpy(persoane[i].CNP, persoane[i+1].CNP);
                    strcpy(persoane[i+1].CNP, aux.CNP);
                    ok=0;
                }
            }
        }
    }    while(ok==0);



    for(i=0; i<= n-1; i++)
    {
        fflush(stdin);
        puts(persoane[i].nume);
         printf("\n");
         fflush(stdin);
        puts(persoane[i].prenume);
        printf("\n");
        fflush(stdin);
        puts(persoane[i].CNP);
        printf("\n");
        fflush(stdin);
    }

}
