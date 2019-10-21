#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//acest program si functiile sunt special implementate pentru vectori de cate 7 valori
// de tip int, dar poate fi modificat si pentru alte valori ale nr de
// componente. In schimb, sirul de caractere caruia i se va aplica metoda insertiei
//poate avea mai mult de 7 caractere, introduse de la tastatura.


void citire_num(int v[])
{
	printf("Introduceti 7 numere intregi de la tastatura:");
	int i;
	for(i=0; i<7; i++)
	scanf("%d", &v[i]);
}

void afisare(int v[])
{
	int i;
	for(i=0; i<7; i++)
	printf("%d ", v[i]);

}

void insert_char(char sir[])
{

    int i,j;
    char k;
    int nr= strlen(sir);
    for (i = 1; i < nr; i++)
   {
       k = sir[i];
       j = i-1;
      while (j >= 0 && sir[j] > k)
       {
           sir[j+1] = sir[j];
           j = j-1;
       }
       sir[j+1] = k;
   }
}



void insert_num(int v[])
{
	int i,j,x;

    for(i=1; i<= 7; i++)
        if (v[i]< v[i-1])
        {
            x= v[i];
            j= i-1;

            while (j>=0 && v[j]>x)
			{
               v[j+1]=v[j];
			   j --;
            }

        v[j+1]=x;

        }
	afisare(v);
}


	void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


 void selection(int v[])
 {

    int i, j, min;
    for (i = 0; i < 6; i++)
    {
        min = i;
        for (j = i+1; j < 7; j++)
          if (v[j] < v[min])
            min = j;
        swap(&v[min], &v[i]);
    }
 	afisare(v);
 }



 void bubble(int v[])
 {
 	int ok, i;
 	do
		{
            ok=1;
            for(i=0; i<=6; i++)
            if(v[i]>v[i+1])

            {
                swap(&v[i],&v[i+1]);
                ok=0;
            }

		}
		while(ok!=1);
        afisare(v);

}

 void merge(int v[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}


int cmp(int v[], int l, int h)
{
    int pivot = v[h];
    int i = (l - 1);
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[h]);
    return (i + 1);
}


void quick(int v[], int l, int h)
{
	if (l < h)
    {
        int pi = cmp(v, l, h);
        quick(v, l, pi - 1);
        quick(v, pi + 1, h);
    }
	afisare(v);
}


void shell(int v[])
{
    int i,g,j,t;
    for (g = 7/2; g > 0; g /= 2)
    {

        for (i = g; i < 7; i ++)
        {
            t = v[i];
            for (j = i; j >= g && v[j - g] > t; j -= g)
                v[j] = v[j - g];
            v[j] = t;
        }
    }

	afisare(v);
}

void counting(int v[])
{
    int i, j;
    int max = v[0];
	for(i=0; i<7; i++)
	if(v[i] > max)
	max = v[i];
	int b[100000]={0};
	for(i=0; i<=max; i++)
	{
		for(j=0; j<7; j++)
	     	if(v[j]==i)
		       b[i]++ ;
	}

	for(i=0; i<= max; i++)
	{
		while(b[i]>0)
		{
			printf("%d,",i);
			b[i]--;
		}
	}

}




int main()
{
	int v[7];
	char sir[100];
	int c;
	int opt;
	printf("Introduceti un sir de caractere sau un vector de numere?\n\tApasati 1 pentru sir de caractere, 2 pentru sir de numere\n ");
	scanf("%d", &opt);
	switch(opt)
	{
		case 1: printf("Introduceti sirul:\n");
                fflush(stdin);
				gets(sir);
				insert_char(sir);
				fflush(stdin);
				puts(sir);
				break;

		case 2: citire_num(v);
				printf("Alegeti algoritmul dorit pentru sortare:\n");
				printf("\t 1- insertion sort; \n");
				printf("\t 2 - selection sort; \n");
				printf("\t 3 - bubble sort; \n");
				printf("\t 4 - merge sort; \n");
				printf("\t 5 - quick sort; \n");
				printf("\t 6 -  shell sort; \n");
				printf("\t 7- counting sort; \n");

				scanf("%d", &c);

				switch(c)
				{
					case 1: insert_num(v); break;
					case 2: selection(v); break;
					case 3: bubble(v); break;
					case 4: mergeSort(v,0,6); break;
					case 5: quick(v,0,6); break;
					case 6: shell(v); break;
					case 7: counting(v); break;
				}
				break;
	}



	return 0;
}
