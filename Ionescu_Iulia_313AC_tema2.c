#include <stdlib.h>
#include <stdio.h>


void adunare(int a[100][100],int b[100][100],int n,int m)
{
	FILE *f;
	f= fopen("Rezultate.txt","w");
	int i,j,c[100][100]={0};

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	fprintf(f,"Adunarea celor doua matrici: \n");
	for(i=0;i<n;i++)
	{
		for(j=0; j<m; j++)
		{
			fprintf(f,"%d ",c[i][j]);
		}
		fprintf(f,"\n");
	}
}

void afis(int a[100][100],int n,int m)
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void inmultire(int a[100][100],int b[100][100],int n,int m,int ok)
{
	FILE *f;
	f=fopen("Rezultate.txt","a+w");
	int i,j,k,c[100][100]={0};
	for(i=0; i<n; i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0; k<n; k++)
			{
				c[i][j]+= a[i][k]*b[k][j];
			}
		}
	}
    for(i=0; i<n; i++)
	for(j=0; j<m; j++)
	b[i][j]=c[i][j];

	if(ok==0)
	{
        fprintf(f,"Inmultire\n");
        for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    fprintf(f,"%d ",c[i][j]);
                }
                fprintf(f,"\n");
            }
    }

	afis(c,n,m);
}


void putere(int c,int a[100][100],int n,int m)
{
	int i,j;
	FILE *f;
	int d[100][100];
	for(i=0; i<n; i++)
	for(j=0; j<m; j++)
	d[i][j] = a[i][j];
	if((f= fopen("Rezultate.txt","a+w"))== NULL)
	{
		printf("Fisierul nu a putut fi deschis");
		exit(1);
	}
	int k=1;
	while(k<=c)
	{
		inmultire(a,d,n,m,1);
		k++;
	}
	fprintf(f,"Ridicarea la putere \n");

	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			fprintf(f,"%d ",d[i][j]);
		}
		fprintf(f,"\n");
	}
}
void citire(int a[100][100],int b[100][100],int *n1,int *m1,int *n2,int *m2)
{
	FILE *f;

	if((f=fopen("Date.txt","r"))==NULL)
	{
		printf("Fisierul nu a putut fi deschis");
		exit(1);
	}

	fscanf(f,"%d",n1);
	fscanf(f,"%d",m1);
	int n=*n1,m=*m1,i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			fscanf(f,"%d",&a[i][j]);
		}
	}
	fscanf(f,"%d",n2);
	fscanf(f,"%d",m2);
    n =*n2;
    m =*m2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(f,"%d",&b[i][j]);
		}
	}
}


int main()
{
	int a[100][100],n1,m1,b[100][100],n2,m2;
	citire(a,b,&n1,&m1,&n2,&m2);
	if(n1==n2 && m1==m2)
	{
		adunare(a,b,n1,m1);
	}
	if(m1==n2)
	{
		inmultire(a,b,n1,m2,0);
	}
	putere(5,a,n1,m1);
	return 0;
}
