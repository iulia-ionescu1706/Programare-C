#include <stdio.h>
#include <stdlib.h>


int sah(int a[],int n,int r)
{
	int i,j;
	if(r==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	else
	{
	for(j=1;j<=n;j++)
	{
		int legal=1;
		for(i=1;i<=r-1;i++)
		{
			if((a[i]==j)||(a[i]==j+r-i)||(a[i]==j-r+i))
			legal=0;
		}
		if(legal==1)
		{
			a[r]=j;
			sah(a,n,r+1);
		}
	}
    }
}
int main() {
	int a[100]={0};
	int n=8;
	sah(a,n,0);
	return 0;
}
