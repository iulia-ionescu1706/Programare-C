#include <stdio.h>
#include <stdlib.h>

struct stiva{
	int x;
	struct stiva *next;
	struct stiva *prev;
};

typedef struct stiva stiva;

stiva* push(stiva *p)
{
	stiva *c=(stiva *)malloc(sizeof(stiva));
	p->next=c;
	scanf("%d",&c->x);
	c->prev=p;
	c->next=NULL;
	return c;
}
stiva* pop(stiva *c)
{
	stiva *k;
	k=c;
	c->prev->next=NULL;
	free(c);
	return k;
}
void afisare(stiva *c)
{

	stiva *k=c;
	do{
		printf("%d,",k->x);
		k=k->next;

	}while(k!=NULL);
	printf("\n");

}
int main()
{
	int n,i;
	stiva *p,*u,*k;
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{

		stiva *c=(stiva *)malloc(sizeof(stiva));
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
