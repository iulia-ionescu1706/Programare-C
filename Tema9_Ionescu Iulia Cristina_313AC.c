#include<stdio.h>
#include<conio.h>

struct Nod{

//struct Nod *nod;
int info;
struct Nod *parinte;
struct Nod *leg_st;
struct Nod *leg_dr;

};
typedef struct Nod Nod;

void Insertie(Nod *prim,int nr)
{
    Nod *nod1, *nod2, *nod3;
    //nod1 = new Nod;
    nod1 = (Nod *) malloc(sizeof(Nod *));
    nod1->info = nr;
    nod1->leg_st = NULL;
    nod1->leg_dr = NULL;
    if(prim == NULL)
    {
        prim = nod1;

    }
    else
    {
        nod2 = prim;
    }
    while(nod2 != NULL)
    {
        if(nr< nod2-> info)
        {
            nod3 = nod2;
            nod2 = nod2->leg_st;
        }
        else
            {
                nod3 = nod2;
                nod2 = nod2 ->leg_dr;
            }
    }
    if(nr<nod2->info)
        nod3->leg_st = nod1;
    else
        nod3->leg_dr = nod1;

}
void Preorder(Nod* rad)
{
    if(rad != NULL)
    {
        printf("%d - ", rad->info);
        Preorder(rad->leg_st);
        Preorder(rad->leg_dr);

    }
}

void Inorder(Nod* rad)
{
    if(rad != NULL)
    {
        Inorder(rad->leg_st);
        printf("%d - ", rad->info);
        Inorder(rad->leg_dr);
    }
}

void Postorder(Nod* rad)
{
    if(rad != NULL)
    {
        Postorder(rad->leg_st);
        Postorder(rad->leg_dr);
        printf("%d - ", rad->info);
    }
}
void Parcurgere(Nod *nod)
{
    if(nod)
    {
        Parcurgere(nod->leg_st);
        printf("%d", nod->info);
        Parcurgere(nod->leg_dr);
    }
}

void Stergere(Nod *rad, int nr)
{
    Nod *tmp, *tmp1,*tmp2;
    tmp1 = rad;
    while(tmp->info != nr)
    {
        if(tmp->info > nr)
            tmp1 = tmp1->leg_st;
        else
            tmp1 = tmp1->leg_dr;
    }
    tmp = tmp1;
    if (tmp1->leg_dr == NULL)
    {
        tmp1->info = tmp1->leg_st->info;
        tmp1->leg_st = tmp1->leg_st->leg_st;
        free(tmp1->leg_st);
    }
    else if(tmp1->leg_st == NULL){
                tmp1->info = tmp1->leg_dr->info;
                tmp1->leg_dr = tmp1->leg_dr->leg_dr;
                free(tmp1->leg_dr);
            }

    else
        {
            tmp = tmp1->leg_dr;
            tmp2 = tmp1;
            while(tmp->leg_st != NULL)
                {
                    tmp2 = tmp;
                    tmp = tmp ->leg_st;
                }
            tmp1->info = tmp->info;
            tmp2->leg_st = NULL;
            free(tmp);

        }

}
Nod *Cautare(Nod *nod, int nr)
{
    if(!nod || nod->info == nr)
        return nod;

    if(nr < nod->info)
        return Cautare(nod->leg_st, nr);
            else return Cautare(nod->leg_dr, nr);
}
 Nod *Minim(Nod *nod)
 {
     while(nod->leg_st != NULL)
        nod = nod->leg_st;
     return nod;
 }
 Nod *Maxim(Nod *nod)
 {
     while(nod->leg_dr != NULL)
        nod = nod->leg_dr;
     return nod;
 }

 Nod *Succesori(Nod *nod, int nr)
 {
     Nod *y;
     while(nod!= NULL)
     {
    if(y->info == nr)
     if(nod->leg_dr != NULL)
        return Minim(nod->leg_dr);
     y= nod->parinte;
     while(y == NULL && nod == y->leg_dr)
     {
         nod = y;
         y = y->parinte;
     }
     }

 }

Nod *Parinte(Nod *nod, int nr)
{
    Nod *y;
    if (nod->leg_st != NULL)
        {
           return  Maxim(nod->leg_st);
        }
    y = nod->parinte;
    while(y != NULL && nod == y->leg_st)
    {
        nod = y;
        y = y->parinte;
    }
    return y;
}



void Creare(Nod* rad)
{
    int nr=0,n,i;
    printf("numar de noduri: \n");
    scanf("%d ", &n);
    for(i=1; i<=n; i++)
    {
		printf("informatia nodului %d:\n ", i);
		scanf("%d", &nr);
		Insertie(rad, nr);
	}
}


void main()
{
    Nod *rad=0;
    int nr,opt;
    Creare(rad);
	do{
		printf("\n\n\t Optiuni:\n 1-Cauta o valoare in arborele binar complet\n 2-Adauga un nod in arborele binar complet\n 3-Sterge un nod din arborele binar complet\n 4-Lista nodurilor in inorder\n 5-Lista nodurilor in preorder\n 6 - Lista nodurilor in postorder\n 7 - Gasirea parintelui\n 8 - Gasirea copiilor\n 9 - Iesire");
	printf("optiunea: \n");
	scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("valoarea: ");
                    scanf("%d", &nr);
                    Cautare(rad, nr);
                    break;
            case 2: printf("valoarea: ");
                    scanf("%d", &nr);
                    Insertie(rad, nr);
                    break;
            case 3: printf("valoarea: ");
                    scanf("%d ", &nr);
                    Stergere(rad,nr);
                    break;
            case 4: Inorder(rad); break;
            case 5: Preorder(rad); break;
            case 6: Postorder(rad); break;
            case 7: Parinte(rad, nr);break;
            case 8: Succesori(rad, nr); break;


		}
	}while(opt!=9);
}

