#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct produs
{
    int cod;
    float pret;
    char nume[20];
    struct produs *urm;
}PROD;

void creare_lista_produse()
{
    PROD *cap_lista = NULL;

}
void inserez_la_inceput(PROD* cap_lista)
{
    PROD *p=(PROD*)malloc(sizeof(PROD));
    if(p == NULL)
    {
        printf("Alocare dinamica esuata");
        exit(1);
    }
    printf("Introduceti codul produsului care sa fie primul:\n");
    scanf("%d",&p->cod);
    printf("Introduceti pretul produsului care sa fie primul:\n");
    scanf("%f",&p->pret);
    printf("Introduceti numele produsului:\n");
    fflush(stdin);
    gets(p->nume);
    p->urm = cap_lista;
    cap_lista = p;
}

void inserez_la_sfarsit(PROD* cap_lista)
{
    PROD *p=(PROD*)malloc(sizeof(PROD));
    if(p == NULL)
    {
        printf("Alocare dinamica esuata");
        exit(1);
    }

     printf("Introduceti codul produsului:\n");
    scanf("%d",&p->cod);
    printf("Introduceti pretul produsului care sa fie primul:\n");
    scanf("%f",&p->pret);
    printf("Introduceti numele produsului:\n");
    fflush(stdin);
    gets(p->nume);

    p->urm = NULL;
     if(cap_lista ==NULL)
     {
         cap_lista= p;
     }
    else
        {
            PROD *q = cap_lista;
            while(q->urm != NULL)
            q = q->urm;
        }
}


//void inserez_dupa(ELEM* n, ELEM* p, int value)
//{
//    ELEM *p=(ELEM*)malloc(sizeof(ELEM));
//    if(p == NULL)
//    {
//        printf("Alocare dinamica esuata");
//        exit(1);
//    }
//    p->val = value;
//    p->urm = NULL;
//    p->urm = n->urm;
//    n->urm = p;
//}

//void inserez_inainte(ELEM* n, ELEM* p)
//{
//    ELEM t;
//    t = *p;
//    *p = *n;
//    *n = t;
//    n->urm =p;
//}
PROD* sterge_elem(PROD* acela, PROD* primul)
{
    PROD* p;
    if(acela == primul)
        primul = acela->urm;
    else
        {
            for(p=primul; ((p!=NULL)&&p->urm != acela); p= p->urm)
            ;
            if(p == NULL)
            {
                printf("Elementul nu exista in lista!");
                return primul;
            }
            p->urm = p->urm->urm;
        }
        free(acela);
        return primul;
}


//void elimina_succesor(ELEM* n)
//{
//    ELEM* t;
//    t = n->urm;
//    n->urm = t->urm;
//    free(t);
//}


PROD* CautarePozitie(PROD* cap, int pozitie)
{
    int i = 0; // pozitia curenta
// parcurge lista pana la
// pozitia ceruta sau pana la
// sfarsitul listei
    while (cap != NULL && i < pozitie)
    {
        cap = cap->urm;
        i++;
    }
// daca lista contine elementul
    if (i == pozitie)
        return cap;
    else
    return NULL;

}
void cauta_elem(PROD* cap_lista)
{
    PROD* p;
    float EPS=0.00001;
    int pret,cod;
    char nume[20];
    printf("Tastati codul produsului cautat:\n");
            scanf("d\n",&cod);
    for(p=cap_lista; p!=NULL; p= p->urm)
        {
             if((p->cod == cod) || ((p->pret - pret)< EPS) || (strcmp(p->nume, nume)==0))
            printf("Elementul a fost gasit\n");
        else printf("Elementul NU a fost gasit\n");
        }

}
void afisare_lista(PROD* cap_lista)
{
    PROD* p;
    int i=1;
    for(p=cap_lista; p!=NULL; p= p->urm)
        {
            printf("Nume produs %d :\n", i++);
            fflush(stdin);
            puts(p->nume);
            printf("Pret produs:%f lei\n\n", p->pret);

        }
}


main()
{
    PROD *p,*q, *cap_lista, *elem_de_adaugat, *acela;
    //int optiune, nr_elem, nr_elem_sters, elem;
    /*creare_lista();*/
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
    afisare_lista(cap_lista);
    printf("Doriti sa adaugati produse in lista?D/N/I(I este pt inserare la inceput-produs prioritar");
    scanf("%c", &opt1);
    switch(opt1)
    {
        case 'D':   inserez_la_sfarsit(cap_lista);
                afisare_lista(cap_lista);
                break;

        case 'I': inserez_la_inceput(cap_lista);
                    afisare_lista(cap_lista);
                    break;

        case 'N':printf("Alegeti alta optiune:S,C,P(s-stergere, p-cautare dupa pozitie,c-cautare dupa alte criterii:\n");
                scanf("%c", &opt2);
                switch (opt2)
                {
                    case 'S':sterge_elem(acela,cap_lista);
                        afisare_lista(cap_lista);
                        break;

                    case 'P': afisare_lista(CautarePozitie(cap_lista,pozitie)); break;
                    case 'C': cauta_elem(cap_lista);break;

                }break;
    }
        //printf("Valoarea elementului cu nr %d este %d\n", i, p->val);




//    printf("Tastati optiunea pe care o doriti:\n\n");
//    printf("1 - pt inserarea dupa un anumit element a altui element\n");
//    printf("2 -  pt inserarea inaintea unui anumit element a altui element\n");
//    printf("3 - pt stergerea din lista a unui anumit element \n");
//    printf("4 - pt stergerea succesorului din lista a unui anumit element\n");
//    printf(" 5 - pt cautarea in lista a unui element \n");
//    scanf("%d", &optiune);
//    switch(optiune)
//    {
//        case 1: printf("Introduceti pozitia din lista dupa care doriti sa faceti inserarea:\n");
//                scanf("%d",&nr_elem);
//                inserez_dupa(cap_lista+nr_elem, elem_de_adaugat);
//                afisare_lista(cap_lista);
//                break;
//        case 2: printf("Introduceti pozitia din lista inaintea careia doriti sa faceti inserarea:\n");
//                scanf("%d",&nr_elem);
//                inserez_inainte(cap_lista+nr_elem, elem_de_adaugat);
//                afisare_lista(cap_lista);
//                break;
//        case 3: printf("Introduceti pozitia din lista a elementului pe care doriti sa-l stergeti:\n");
//                scanf("%d",&nr_elem_sters);
//                sterge_elem(cap_lista+nr_elem_sters, cap_lista);
//                afisare_lista(cap_lista);
//                break;
//        case 4: printf("Introduceti pozitia din lista a elementului dinaintea celui pe care doriti sa-l stergeti:\n");
//                scanf("%d",&nr_elem);
//                elimina_succesor(cap_lista+nr_elem);
//                afisare_lista(cap_lista);
//                break;
//        case 5: printf("Introduceti elementul cautat:\n");
//                scanf("%d", &elem);
//                cauta_elem(elem, cap_lista);
//                afisare_lista(cap_lista);
//                break;
//    }

}
