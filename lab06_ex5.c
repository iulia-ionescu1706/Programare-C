#include<stdio.h>

/*Ionescu Iulia - 313AC*/
int pozmin(int v[], int n)
{
    int i,j = 0, poz[10], nr=0, min = v[0];

    for (i =0; i<= n-1; i++ )
    {
        if(v[i] < min)
            min = v[i];
            nr = nr + 1;
    }
    for (i =0; i<= n-1; i++)
    {

        if(v[i]== min)
        poz[j++] = i;

    }
    return(*poz);


}

main()
{
    int v[20], i,n;
    printf("Cate elemente contine vectorul?");
    scanf("%d", &n);
    printf("Citeste vectorul:");
    for(i=0; i<= n-1; i++)
    {
        scanf("%d", &v[i]);
    }
    pozmin(v,n);
}
