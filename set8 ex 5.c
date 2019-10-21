#include<stdio.h>

typedef struct fig_geom
{
    char nume;
    union dimensiune
    {
        int raza;
        int lungime;
        int latime;
    }dimensiune;
};

main()
{
    struct fig_geom fig;
    double perimetru = 0;
    double arie= 0;
    printf("Citeste litera pentru tipul figurii: c- cerc, p- patrat, d-dreptunghi");
    scanf("%c", &fig.nume);
    if(fig.nume =='c')
    {
        printf("Precizeaza raza cercului:");
        scanf("%d", &fig.dimensiune.raza);
        perimetru = 2* 3.14 *fig.dimensiune.raza;
        arie = 3.14*((fig.dimensiune.raza)^2);
        printf("Perimetrul figurii %c este %f, iar aria este %f", fig.nume, perimetru, arie);
    }
    if(fig.nume == 'p')
    {
        printf("Precizeaza latura patratului:");
        scanf("%d", &fig.dimensiune.lungime);
        perimetru = 4* fig.dimensiune.lungime;
        arie = fig.dimensiune.lungime^2;
        printf("Perimetrul figurii %c este %f, iar aria este %f", fig.nume, perimetru, arie);

    }
    if(fig.nume == 'd')
    {
        printf("Precizeaza lungimea si latimea dreptunghiului:");
        scanf("%d", &fig.dimensiune.lungime);
        scanf("%d", &fig.dimensiune.latime);
        perimetru = 2* (fig.dimensiune.lungime + fig.dimensiune.latime);
        arie = fig.dimensiune.lungime*fig.dimensiune.latime;
        printf("Perimetrul figurii: %c este %f, iar aria este: %f", fig.nume, perimetru, arie);
    }



}
