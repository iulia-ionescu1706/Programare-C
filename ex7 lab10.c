#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct AUTOMOBIL
{
    char marca[20];
    char carburant;
    char model[13];
    struct data
    {
        int luna;
        int an;
    }data;
}AUTO;
void citire()
{
    FILE *f;
    AUTO masini[20];
    f=fopen("parc_auto.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    int i,n;
    printf("Cate masini sunt in parcul auto?");
    scanf("%d\n",&n);
    getch();
    for(i=0; i<n;i++)
    {
        printf("Cititi marca masinii:\n");
        printf("Cititi tipul de carburant, benzina(B) sau motorina(M):\n");
        printf("Cititi modelul masinii:\n");
        printf("Cititi data (luna, si anul):\n");
        scanf("%s", masini[i].marca);
        scanf("%c",&masini[i].carburant);
        scanf("%s", masini[i].model);
        scanf("%d\n%d\n", &masini[i].data.luna, &masini[i].data.an);
        fwrite(&masini[i],sizeof(masini[i]),1,f);
    }
     fclose(f);
 }

 void adaugare(FILE *f)
 {
     int c;
    AUTO masini[20];
    f=fopen("parc_auto.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    AUTO mas_noua;
        printf("Doriti sa adaugati masini noi in evidenta? (1/0)");
        scanf("%d", &c);
        switch(c)
        {
            case 1:   printf("Cititi marca masinii:\n");
                        scanf("%s", mas_noua.marca);
                        printf("Cititi tipul de carburant, benzina(B) sau motorina(M):\n");
                        scanf("%c",&mas_noua.carburant);
                        printf("Cititi modelul masinii:\n");
                        scanf("%s", mas_noua.model);
                        printf("Cititi data (luna, si anul):\n");
                        scanf("%d\n%d\n", &mas_noua.data.luna, &mas_noua.data.an);
                        fseek(f,0L,2);
                        fwrite(&mas_noua, sizeof(AUTO),1,f);
                        break;
            case 0:   break;

        }
        fclose(f);
}
  int gasire()
  {
      char marca[20];
      char carb;
      int gasit=0;
      printf("Precizati marca pe care o cautati:\n");
      scanf("%s",marca);
      printf("Precizati tipul de carburant cautat:\n");
      scanf("%c", carb);
      FILE *f;
    AUTO masini[20];
    f=fopen("parc_auto.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    int i,n;
    printf("Cate masini sunt in parcul auto?");
        scanf("%d\n",&n);
    fread(masini, sizeof(masini[0]),n,f);
    for(i=0;i<n;i++)
    {
        if(strcmp(masini[i].marca,marca)==0 && masini[i].carburant == carb)
            gasit =1;
    }
    return gasit;
  }

  void lista_vechi()
  {
    int an_curent=2018;
    int luna_curenta=1;
    int i,n, f1op=0;

    FILE *f, *f1;
    AUTO masini[20];

    f=fopen("parc_auto.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    printf("Cate masini sunt in parcul auto?");
        scanf("%d\n",&n);
    fread(masini, sizeof(masini[0]),n,f);
    for(i=0;i<n;i++)
    {
        if(masini[i].data.an <= (an_curent-5))
            {
                if(masini[i].data.luna <= luna_curenta)
                {
                    f1=fopen("masini_vechi.dat","wb");
                    f1op=1;
                    if(f1==0)
                    {
                        printf("Fisierul nu a putut fi deschis!\n");
                        exit(1);
                    }
                    fwrite(&masini[i],sizeof(masini[i]),1,f1);

                }
            }
            else printf("Nu exista masini cu vechimea mai mare de cinci ani");



    }
    if (f1op==1)
    {fclose(f1);}
    fclose(f);
}


  void info_decap()
  {
      FILE *f, *fdecap;
    AUTO masini[20];
    int an_prod,i, n;

    f=fopen("parc_auto.dat","wb");
    if(f==0)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        exit(1);
    }
    printf("Cate masini sunt in parcul auto?");
        scanf("%d\n",&n);
    fread(masini, sizeof(masini[0]),n,f);
    printf("Introduceti anul productiei:");
    scanf("%d",&an_prod);

    for(i=0;i<n;i++)
    {
        if(strcmp(masini[i].model,"decapotabila")==0)
        {
            if(masini[i].data.an == an_prod)
            {
                fdecap=fopen("decapotabile.dat","wb");
                if(fdecap ==0)
                {
                    printf("Fisierul nu a putut fi deschis!\n");
                    exit(1);
                }
                fwrite(&masini[i],sizeof(masini[i]),1,fdecap);

            }
        }

    }
  }

 main()
 {
        FILE *f;
        AUTO masini[30];
        int optiune;
        printf("Ce functie doriti sa utilizati? Tastati: 1- pentru citirea informatiilor in fisier;\n");
        printf("2- pentru adaugarea unei noi masini in parcul auto;\n");
        printf("3 - pentru gasirea unui anumit automobil dupa marca si tipul de carburant:\n");
        printf("4 - pentru intocmirea unei liste cu masini cu vechime mai mare sau egala cu 5 ani;\n");
        printf("5 - pentru gasirea informatiilor despre masinile decapotabile;\n");
        printf("Tastati optiunea dvs:\n");
        scanf("%d",&optiune);
        switch(optiune)
        {
            case 1:citire();break;
            case 2: adaugare(f); break;
            case 3: gasire(); break;
            case 4: lista_vechi(); break;
            case 5: info_decap(); break;
            default: printf("Nu ati tastat o cifra corespunzatoare, rulati din nou programul!");
        }
 }

