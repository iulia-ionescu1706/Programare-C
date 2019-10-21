#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda
{
	int key;
	char nume[10000];
	char numar[10000];
	struct agenda *next,*prev;
};

typedef struct agenda agenda;

agenda* adaugare(agenda *s)
{

	agenda *c=(agenda *)malloc(sizeof(agenda));
	printf("Introduceti numele persoanei adaugate:\n");
	fflush(stdin);
	gets(c->nume);
	printf("Introduceti nr de telefon al persoanei respective:\n");
	fflush(stdin);
	gets(c->numar);
	c->key=s->key+1;
	c->prev=s;
	s->next=c;
    printf("%d %s % s\n",c->prev->key,c->prev->nume,c->prev->numar);
    return c;
}
void stergere(agenda *s)
{
	agenda *c=s;
	agenda *k;
	printf("Indexul elementului sters : ");
	int n;
	scanf("%d",&n);
	int ok=0;
	while(c!=NULL)
	{
		if(n==c->key)
		{
			ok=1;
			k=c;
			c->prev->next=c->next;
		}
		if(ok==1)
		{
			c->key--;
		}
		c=c->next;
	}
	free(k);
}

void cautare(agenda *s)
{
	char d[1000];
	agenda *c=s;
	printf("Introduceti numele : ");
	fflush(stdin);
	gets(d);
	while(c->next!=NULL)
	{
		if(strcmp(d,c->nume)==0)
		{
			puts(c->nume);
			printf("\n");
			puts(c->numar);
		}
		c=c->next;
	}
}
void p_u(agenda *p)
{
	agenda *c = p;
	if(c->next!=NULL)
	{

	while(c!=NULL)
	{
		printf("%d %s % s\n",c->key,c->nume,c->numar);
		c=c->next;
	}
			printf("\n");
	}

	else
	{
	    printf("!\n");
	}
}
void hashfct(agenda *p,int key)
{
	agenda *c=p;

	while(c!=NULL)
	{
	if(c->key==key)
	{printf("%d %s % s\n",c->key,c->nume,c->numar);
	}
	c=c->next;
	}
	printf("\n");
}

int main()
 {
	agenda *p,*u,*k;
	int n, i, pm;
	 printf("Introduceti nr de persoane din agenda:");
	scanf("%d",&n);
	fflush(stdin);
	p=(agenda *)malloc(sizeof(agenda));
	p->key=1;
	gets(p->nume);
	fflush(stdin);
	gets(p->numar);
	p->next=NULL;
	p->prev=NULL;
	u=p;
	for(i=1;i<n;i++)
	{
		p=adaugare(p);
	}
	k=p;
	p=u;
	u=k;
	p_u(p);
	stergere(p);
	p_u(p);
	cautare(p);
    printf("\nCautare indexul : ");
    scanf("%d",&pm);
	hashfct(p,pm);
	return 0;
}
