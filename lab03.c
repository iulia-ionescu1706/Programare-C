#include<stdio.h>
 int pare( int v[10])
{
    int i, n;
    printf("Tastati cate numere doriti sa introduceti:\n");
    scanf("%d", &n);
    printf(" Tastati numerele intregi\n");
    for (i=0; i <= n-1; i++ )
        {
            scanf("%d", &v[i]);
        }
    for (i=0; i <= n-1; i++ )
        if ( v[i] % 2 == 0)
        {
            printf("%d\n", v[i]);
        }

    return 0;
}

int fPrag( int v[10])
{
    int i, n,prag;
    printf("Introduceti pragul:");
    scanf("%d", &prag);
    printf("Tastati cate numere doriti sa introduceti:\n");
    scanf("%d", &n);
    printf(" Tastati numerele intregi\n");
    for (i=0; i <= n-1; i++ )
        {
            scanf("%d", &v[i]);
        }
    for (i=0; i <= n-1; i++ )
    {
        if(v[i] > prag)
        {
            printf("%d,\n", v[i]);
        }
    }
    return 2;

}


int nrdivvect(int v[10])
{
    int i, n,j, ndiv;
    printf("Tastati cate numere doriti sa introduceti:\n");
    scanf("%d", &n);
    printf(" Tastati numerele intregi\n");
    for (i=0; i <= n-1; i++ )
        {
            scanf("%d", &v[i]);
        }
    for (i=0; i <= n-1; i++ )
    {
        ndiv = 0;
        for (j = 1; j <= v[i]; j++)
        {
            if( v[i] % j == 0) ndiv++;
        }

        v[i]= ndiv;
        }

    for (i=0; i<= n-1; i++)
        printf("%d \n", v[i]);
}

int elim0(int v[10])
 {int i, n, j, ok;
    printf("Introduceti un numar de elemente <10:\n");
    scanf("%d", &n);
    printf("Introduceti elementele:");
    for(i =0; i <= n-1; i++)
    {
        scanf("%d/n", &v[i]);
    }
    ok=0;
     for(i =0; i< n; i++)
     {
        if(v[i] ==0 )
        {
            v[i]= v[i+1];
            i= i-1;
            ok ++;
        }
     }
     for(j =0; j< n-ok; j++)
     {
         printf("%d ", v[j]);
    }
 }



 int matrice(int m[10][10])
  {int aux[10], i, j,k,l,c;
    printf("cititi nr de linii:") ;
    scanf("%d/n",&l);
    printf("cititi nr de coloane:");
    scanf("%d/n", &c);
    printf("cititi elementele matricei:");
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            scanf("%d/n",&m[i][j]);
        }
    }
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            printf("%d ",m[i][j],"/n");

        }
    }
    k=0;
    for(i=0; i<= l-1; i++)
    {
        aux[k]=m[i][0];
        m[i][0]=m[i][1];
        m[i][1]=aux[k];
        k++;
    }
    for(i=0; i<= l-1; i++)
    {
        for(j=0; j<= c-1; j++)
        {
            printf("%d\n",m[i][j]);
        }
    }

}

int pareimp(int v[10])
{


int par[10], imp[10], i, n, j,k, pare=0, impare=0;
    printf("Introduceti un numar de elemente <=10:\n");
    scanf("%d", &n);
    printf("Introduceti elementele:");
    for(i =0; i <= n-1; i++)
    {
        scanf("%d/n", &v[i]);
    }

    for(i =0; i <= n-1; i++)
    {
        if (v[i]%2 == 0)
        {
            par[k++]=v[i];
            pare++;
        }
        else
        {
            imp[j++]=v[i];
            impare++;
        }

    }
    printf("Pare:");
    for(k =0; k <= pare-1; k++)
        printf("%d ", par[k]);
        printf("\n");
    for(j=0; j <= impare-1; j++)
        printf("%d ", imp[j]);

}







main()
{
    int vector[10], matr[10][10], raspuns;

    printf("Ce functie doriti? 1- pare;\n 2-prag;\n 3- nr divizori;4- eliminare zerouri;\n 5- matrice;\n 6- pare/impare \n 0-iesire");
    scanf("%d", &raspuns);
    switch(raspuns)
    {   case 1: pare(vector);break;
        case 2: fPrag(vector);break;
        case 3: nrdivvect(vector);break;
        case 4: elim0(vector);break;
        case 5: matrice(matr);break;
        case 6: pareimp(vector);break;
        case 0: break;
    }


}
