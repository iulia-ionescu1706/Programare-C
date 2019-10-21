#include <stdio.h>
#include <stdlib.h>


int labirint(int a[][100],int n,int i,int j)
{
     if(i==n-1 && j==n-1)
     {
     	a[i][j]=2;
	    return 1;
     }

     if(i>=0 && j>=0 && i<n && a[i][j]==1 )
     {
     	a[i][j]=2;
     	if(labirint(a,n,i,j+1))
     	return 1;
    	if(labirint(a,n,i-1,j))
     	return 1;
     	if(labirint(a,n,i+1,j))
     	return 1;
     	if(labirint(a,n,i,j-1))
     	return 1;

     	a[i][j]=1;
     	return 0;
	 }
	 return 0;
}
int main() {

	int a[100][100]={
	{1, 0, 1, 0, 0},
	{1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0},
	{1, 1, 0, 1, 1},
	{0, 1, 1, 1, 1},
	};
	int i,j,n=5;
	int b[100][100];
	for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            b[i][j]=a[i][j];

	if(labirint(b,n,0,0))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			printf("%d ",b[i][j]);

			printf("\n");
		}

	}
	else
	printf("Nu exista solutie");

	return 0;
}
