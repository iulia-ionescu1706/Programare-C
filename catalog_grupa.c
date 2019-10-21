#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct elev
{
    char nume [30];
    char prenume[30];
    float medie;
}ELEV;

void citire_info(FILE *f, ELEV elevi[])
{
    //ELEV elevi[10];
    ELEV e;
    int n,i,k=0;
    f= fopen("elevi.dat", "wb");
    if(f==NULL)
    {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    printf("Cati elevi introduceti in evidenta?");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Citeste numele:");
        fflush(stdin);
        gets(e.nume);
        printf("Citeste prenumele:");
        fflush(stdin);
        gets(e.prenume);
        printf("Introduceti media:");
        scanf("%f", &e.medie);
        fwrite(&e, sizeof(ELEV), 1, f);
        elevi[k++]=e;
    }
    fclose(f);
}

void afisare_info_fisier()
{
    FILE *f;
    ELEV e;
    int n,i;
    f= fopen("elevi.dat", "rb");
    if(f==NULL)
    {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(ELEV);
    fseek(f, 0L, 0);
    for(i=1;i<=n;i++)
    {
        fread(&e, sizeof(ELEV),1,f);
        printf("\n\nNume:\t\n");
        fflush(stdin);
        puts(e.nume);
        printf("\nPrenume:\t");
         fflush(stdin);
        puts(e.prenume);
        printf("\nMedie:\t");
        printf("%f", e.medie);
    }
    fclose(f);

}
void afisare_medie_max(FILE *f)
{
    ELEV elevi[10];
    ELEV e;
    int n,i,j,k=0, poz=0;
    float medmax = 0.0;
    char numestud[30]="";
    citire_info(f,elevi);

    f= fopen("elevi.dat", "rb");
    if(f==NULL)
    {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }

    fseek(f,0L,2);
    n=ftell(f)/sizeof(ELEV);
    fseek(f, 0L, 0);
    for(i=1;i<=n;i++)
    {
        fread(&e, sizeof(ELEV),1,f);
        elevi[k++]=e;
    }

    medmax = elevi[0].medie;
    for(i=1;i<=n;i++)
    {

        if(elevi[i].medie > medmax)
            {
                medmax= elevi[i].medie;
                poz=i;
            }

    }
    printf("Numele studentului cu cea mai mare medie este\n:");
    fflush(stdin);
    puts(elevi[poz].nume);
    printf("Media cea mai mare este a lui si este egala cu\n:");
    printf("%f", medmax);

    }

    void ordonare_dupa_medii(FILE *f)
    {
        ELEV elevi[20];
        ELEV aux,e;
        int i,n,j,h,k=0;
        citire_info(f,elevi);
        f= fopen("elevi.dat", "wb");
        if(f==NULL)
        {
            printf("Fisierul nu poate fi deschis");
            exit(1);
        }

        fseek(f,0L,2);
        n=ftell(f)/sizeof(ELEV);
        fseek(f,0L,0);
        for(i=1;i<=n;i++)
        {
            fread(&e, sizeof(ELEV),1,f);
            elevi[k++]=e;
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1; j<=n; j++)
            {
                if (elevi[i].medie > elevi[j].medie)
                    {
                        aux=elevi[i];
                    elevi[i]=elevi[j];
                    elevi[j]=aux;

                    }
            }
        }
       // for(i=1;i<=n;i++)
        //fwrite(elevi,sizeof(ELEV),1,f);
        //fseek(f,0L,2);
        //n=ftell(f)/sizeof(ELEV);
        for(h=n;h>=1;h--)
        {
            printf("\n\n%f\n", elevi[h].medie);
        fflush(stdin);
        puts(elevi[h].nume);
        printf("\n");
        }

        //afisare_info_fisier();
    }
    void media_mediilor(FILE *f)
    {
         ELEV elevi[10];
    ELEV e;
    int n,i,j,k=0;
    float med;
    float suma=0.0;
    citire_info(f,elevi);
    f= fopen("elevi.dat", "rb");
    if(f==NULL)
    {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    fseek(f,0L,2);
    n=ftell(f)/sizeof(ELEV);
    fseek(f,0L,0);

    for(i=1;i<=n;i++)
    {
        fread(&e,sizeof(ELEV),1,f);
        elevi[k++]=e;
    }

    for(i=0;i<n;i++)
      {
          suma+=elevi[i].medie;
      }
      med=suma/n;
      printf("\nMedia mediilor este:%f\t", med);


    fclose(f);

    }

    void mijloc()
    {
        FILE *f;
        int n, poz;
        ELEV elevi[14];
        long jum;
        f= fopen("elevi.dat", "rb");
    if(f==NULL)
    {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    fread(elevi, sizeof(ELEV),n,f);
    fseek(f,0L,2);
    n=ftell(f)/sizeof(ELEV);
    if(n%2 ==0)
    {
        printf("Nr.obiectelor din fisier este par!");
    }
    else
        {
            jum= 1+(n/2);
            fseek(f, jum, 0);
            poz= ftell(f)/sizeof(ELEV);
            printf("%f\n", elevi[poz].medie);
            printf("%s\t\n",elevi[poz].nume);
        }

    }

main()
{
        FILE *f;
        ELEV elevi[10];
        //citire_info(f);

        //afisare_medie_max(f);
        //afisare_info_fisier();
            media_mediilor(f);
        //ordonare_dupa_medii(f);

        //mijloc();
}
