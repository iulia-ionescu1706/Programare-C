#include <stdio.h>
#include <stdlib.h>


struct lista{
	int x;
	struct lista *next;
	struct stiva *prev;
};


typedef struct lista lista;

lista* push(lista *p)
{
	lista *c=(lista *)malloc(sizeof(lista));
	p->next=c;
	scanf("%d",&c->x);
	c->prev=p;
	c->next=NULL;
	return c;
}
lista* pop(lista *c)
{
	lista *k;
	k=c;
	c->prev->next=NULL;
	free(c);
	return k;
}
void afisare(lista *c)
{

	lista *k=c;
	do{
		printf("%d,",k->x);
		k=k->next;

	}
	while(k!=NULL);
	printf("\n");

}
void afisarereverse(lista *u)
{
	lista *k=c;
	do{
		printf("%d,",k->x);
		k=k->prev;

	}
	while(k!=NULL);
	printf("\n");
}
int main( )
 {
	int n,i;
	stiva *p,*u,*k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{

		lista *c=(lista *)malloc(sizeof(lista));
		scanf("%d",&c->x);
		if(i==0)
		{
		c->prev=NULL;
		c->next=NULL;
		p=c;
		k=p;
        }
        else
        {
        	k->next=c;
        	c->prev=k;
        	c->next=NULL;
        	k=c;
        	if(i==n-1)
        	u=c;
		}

	}
	afisare(p);
	u=push(u);
	afisare(p);
	u=pop(u);
	afisare(p);
	return 0;
}
