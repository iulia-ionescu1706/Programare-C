#include<stdio.h>

typedef struct nr_complex
    {
        int real;
        int imaginar;
    }  ;

struct nr_complex functieadunare(struct nr_complex x, struct nr_complex y)
{
    struct nr_complex rezultat;

    rezultat.real = x.real + y.real;
    rezultat.imaginar = x.imaginar + y.imaginar;
};


main()
{
    struct nr_complex z1, z2,suma;
    scanf("%d",&z1.real);
    scanf("%d",&z1.imaginar);
    scanf("%d",&z2.real);
    scanf("%d",&z2.imaginar);
    suma = functieadunare(z1, z2);
    printf("%d\n", suma.real);
    printf("%d", suma.imaginar);
}
