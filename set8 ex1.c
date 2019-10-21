#include<stdio.h>


 typedef struct nr_complex
    {
        int real;
        int imaginar;
    }  ; /*typedef struct nr_complex NRCMP;*/


     int adunarereal(struct nr_complex x, struct nr_complex y)
    {
        struct nr_complex rezultat;
        rezultat.imaginar = 0;
        rezultat.real = x.real + y.real;
        return rezultat.real;

    }

     int adunareimaginar(struct nr_complex x, struct nr_complex y)
    {
        struct nr_complex rezultat;
        rezultat.real=0;
        rezultat.imaginar = x.imaginar + y.imaginar;
        return rezultat.imaginar;
    }

main()
{
    struct nr_complex z1, z2,sumareal, sumaimaginar;
    scanf("%d",&z1.real);
    scanf("%d",&z1.imaginar);
    scanf("%d",&z2.real);
    scanf("%d",&z2.imaginar);

    printf("%d\n%d\n",adunarereal(z1, z2),adunareimaginar(z1,z2));

    }





