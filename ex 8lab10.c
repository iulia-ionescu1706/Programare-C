#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct angajat
{
    char nume[40];
    int varsta;
    struct
    {
        char denum[30];
        int nr;
        char localitate[30];
    }firma;
}ANGAJAT;


void citire()
{
    FILE *f;
    ANGAJAT angajati[20];
    f=fopen("evid_angajati.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    int i,n;
    printf("Cati angajati sunt?");
    scanf("%d\n",&n);
    for(i=0; i<n;i++)
    {
        printf("Cititi numele angajatului:\n");
        gets(angajati[i].nume);
        printf("Cititi varsta:\n");
        scanf("%d",&angajati[i].varsta);
        printf("Cititi denumirea firmei unde lucreaza:\n");
        gets(angajati[i].firma.denum);
        printf("Cititi numele localitatii unde se afla firma:\n");
        gets(angajati[i].firma.localitate);
        printf("Cititi numarul de angajati al acestei firme:");
        fwrite(&angajati[i],sizeof(angajati[i]),1,f);
    }
     fclose(f);
 }

void adaugare()
{
    char c;
    int ok;

    FILE *f;
    ANGAJAT angajati[20];
    f=fopen("evid_angajati.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }

     do{
        ok =0;

        printf("Doriti sa adaugati angajati noi in evidenta? (D/N)");
        scanf("%c", c);

        ANGAJAT angajat_nou;

        switch(c)
        {
            case 'D':   ok=1;
                        printf("Cititi numele angajatului:\n");
                        gets(angajat_nou.nume);
                        printf("Cititi varsta:\n");
                        scanf("%d",&angajat_nou.varsta);
                        printf("Cititi denumirea firmei unde lucreaza:\n");
                        gets(angajat_nou.firma.denum);
                        printf("Cititi numele localitatii unde se afla firma:\n");
                        gets(angajat_nou.firma.localitate);
                        printf("Cititi numarul de angajati al acestei firme:");
                        fseek(f,0L,2);
                        fwrite(&angajat_nou, sizeof(ANGAJAT),1,f);
                        break;
            case 'N':   ok=1;
                        break;
            default:    printf("Nu ati introdus o litera corecta!\n");
                        ok=0;

        }

        }while(ok==0);
    fclose(f);
}

float gasire_varsta_medie()
{
    int i,n, k=0, sum = 0;
     float med = 0.0;
     long nr = 0;
     long pozitii[15];
    FILE *f;
    ANGAJAT angajati[30];
    f= fopen("evid_angajati.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis");
        exit(1);
    }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(ANGAJAT);
    fseek(f,0L,0);
    for(i=0; i<= n - 1; i++)
        sum += angajati[i].varsta;
    med = (float)sum / n;
    return med;

    }
    long gasire()
    {
            FILE *f;
            int i,n, k=0;
            long nr=0;
            long pozitii[10];
            ANGAJAT angajati[25];
            fseek(f, 0L, 0);
            n=ftell(f)/sizeof(ANGAJAT);
            fseek(f, 0L, 0);
            for(i=0; i <= n-1; i++)
            if (angajati[i].varsta < gasire_varsta_medie())
            {
                nr = ftell(f);
                pozitii[k++] = nr;
            }
            return pozitii;

    }

    void fct_localitati()
    {
        FILE *f, *p;
        int j,i,n, nrloc;
        ANGAJAT angajati[20];
        f=fopen("evid_angajati.dat","wb");
        if(f==0)
        {
            printf("Fisierul nu a putut fi deschis!\n");
            exit(1);
        }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(ANGAJAT);
    fseek(f,0L,0);
    for(i=0; i<= n-1; i++)
    {
        for(j=i; j<=n-1; j++)
        {
            if(strcmp(angajati[i].firma.localitate, angajati[j].firma.localitate)!= 0 )
            {
                nrloc = i;

            }
    }
    }

main()
{
    int pozitii[12], n;
    FILE *f;
    ANGAJAT angajati[30];
    citire();
    adaugare();
     f= fopen("evid_angajati.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis");
        exit(1);
    }
    fseek(f,0L,2);
    n=(ftell(f))/(sizeof(ANGAJAT));
    fseek(f,0L,0);

    int i;
    for(i=0; i<= n - 1; i++)


}
