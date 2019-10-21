#include <stdio.h>
#include <stdlib.h>


void muchie(int v[][100])
{
	int a;
	printf("Nod plecare : ");
	scanf("%d",&a);
	int b;
	printf("Nod final :");
	scanf("%d",&b);
    v[a][b]=1;

	printf("\n");
}
int latime(int v[][100],int n,int p,int x[])
{
	int ok=0;
    int i, c=1;
	for(i=p+1;i<=n;i++)
	{
		if(v[p][i]==1)
		{

			ok=1;
			while(x[c]!=0)
            {
                c++;
            }
            x[c]=i;
		}

	}

	if(ok==0)
	{
	return 0;
    }
    else
    {
        for(i=p; i<n; i++)
        {
            latime(v,n,x[i],x);
        }
    }

}
int lungime(int v[][100],int n,int nod)
{
	int ok=0;
    int i;
	printf("%d ",nod);
	for(i=nod+1;i<=n;i++)
	{
		if(v[i][nod]==1)
		{
			ok=1;

			lungime(v,n,i);


		}
	}

	if(ok==0)
	{
        return 0;
    }
}
int main() {


	int a[100][100],n,i,j;
	printf("Numarul de noduri : ");
	scanf("%d",&n);
	for(i=1;i<n;i++)
    {
        int c;
        printf("Nod plecare : ");
        scanf("%d",&c);
        int b;
        printf("Nod final :");
        scanf("%d",&b);
        a[c][b]=1;
        a[b][c]=1;
    }


	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	  printf("%d ",a[i][j]);
	  printf("\n");
    }

    lungime(a,n,1);
	int v[100];
	printf("\n");
	latime(a,n,1,v);
	v[0]=1;

	for(i=0;i<n;i++)
	{
	    printf("%d ",v[i]);
	}
	return 0;
}
