#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>

typedef struct produs
{
    int cod;
    float pret;
    char nume[20];
    struct produs *urm;
}PROD;



void afisare_lista(PROD *cap_lista)
{
    PROD *p;
    p=cap_lista;
    for(p=cap_lista; p!=NULL; p=p->urm)
    {
        printf("\nNume produs:\t");
        fflush(stdin);
        puts(p->nume);
        printf("\nPret: \t%f\n\n",p->pret);
    }
}

void sterge_elem(float valoare, PROD* cap_lista)
{
    PROD *p, *q;
    float EPS = 0.0001;
    int gasit=0;

    if(abs(cap_lista->pret - valoare)< EPS)
    {
         cap_lista=cap_lista->urm;
         //free(p);
        afisare_lista(cap_lista);

    }
    q=cap_lista;
    for(q=cap_lista; q!=NULL; q= q->urm)
    {

            if(abs(q->pret - valoare)<EPS)
            {
                gasit=1;
                p=q->urm;
                q->urm = q->urm->urm;
                free(p);
                //free(q);
                afisare_lista(cap_lista);
            }
    }
            if(gasit==0)
                printf("Produsul cu pretul dat nu se afla in lista");
}


main()
{
    PROD *p,*q, *cap_lista, *elem_de_adaugat, *acela;
    //int optiune, nr_elem, nr_elem_sters, elem;
    /*creare_lista();*/
    float valoare;
    int i, nr,nrproduse, pozitie;
    char opt1,opt2;
    printf("Cate produse doriti sa cumparati?\n");
    scanf("%d", &nr);
    p = (PROD*)malloc(sizeof(PROD));
    if(p==NULL)
    {
        printf("Alocare dinamica esuata!");
        exit(1);
    }
    printf("Introduceti codul produsului care sa fie primul:\n");
    scanf("%d",&p->cod);
    printf("Introduceti pretul produsului care sa fie primul:\n");
    scanf("%f",&p->pret);
    printf("Introduceti numele produsului care sa fie primul:\n");
    fflush(stdin);
    gets(p->nume);


    p->urm = NULL;
    cap_lista =p;
    for(i=2; i<=nr; i++)
    {
        q = (PROD*)malloc(sizeof(PROD));
        if(q == NULL)
            {
                printf("Alocare dinamica esuata!");
                exit(1);
            }
            printf("Introduceti codul produsului:\n");
    scanf("%d",&q->cod);
    printf("Introduceti pretul produsului:\n");
    scanf("%f",&q->pret);
    printf("Introduceti numele produsului:\n");
    fflush(stdin);
    gets(q->nume);
//        printf("Tastati valoarea elementului %d:\n",i);
//        scanf("%d", &q->val);
        q->urm = NULL;
        p->urm = q;
        p = q;
    }
    printf("Lista s-a creat cu succes!\n\n");
    printf("introdu valoarea de pret a produsului care trebuie sters din lista:\n");
    scanf("%f",&valoare);
    sterge_elem(valoare,cap_lista);
    afisare_lista(cap_lista);
}
