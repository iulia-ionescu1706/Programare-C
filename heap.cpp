#include <stdio.h>
#include <stdlib.h>


void heap(int a[], int n, int i)
{
    int k, j = i;
    int s = 2*i + 1;
    int d = 2*i + 2;

    if (s < n && a[s] > a[j])
        j = s;


    if (d < n && a[d] > a[j])
        j = d;

    if (j != i)
    {
    	k =a[i];
    	a[i]=a[j];
    	a[j]=k;

        heap(a, n, spot);
    }
}
void heapSort(int a[], int n)
{

    for (i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);


    for (i= n-1; i>=0; i--)
    {

        int k = a[0];
        a[0]=a[i];
        a[i]=k;
        heap(a, i, 0);
    }
}

int main(int argc, char** argv) {

	int a[100],n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapSort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
	return 0;
}
