#include <stdio.h>

void muchie(int v[][100])
{
	int a;
	printf("Nod plecare : ");
	scanf("%d",&a);
	int b;
	printf("Nod final :");
	scanf("%d",&b);
    v[a][b]=1;
    v[b][a]=1;
	printf("\n");
}
int latime(int v[][100],int n,int p)
{
	int i, ok=0;

		printf("%d ",p);
	for(i=p+1;i<=n;i++)
	{
		if(v[p][i]==1)
		{

			ok=1;

			latime(v,n,i);
		}
	}

	if(ok==0)
	{
        return 0;
    }

}
int lungime(int v[][100],int n,int nod)
{
	int i, ok=0;

	printf("%d ",nod);
	for(i=nod+1;i<=n;i++)
	{
		if(v[i][nod]==1)
		{
			ok=1;

			lungime(v,n,i);
			lungime(v,n,nod);

		}
	}

	if(ok==0)
	return 0;

}
int main(int argc, char** argv) {


	int a[100][100],n,i,j;
	printf("Numarul de noduri : ");
	scanf("%d",&n);
	for(i=1; i<n; i++)
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
   // lungime(a,n,1);
   latime(a, n, i);

	return 0;
}
