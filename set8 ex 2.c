#include<stdio.h>

typedef struct timp
{
    int ora;
    int minut;
    int secunda;
};

struct timp functie(struct timp t1, struct timp t2)
{
    struct timp rezultat;
    rezultat.secunda = t1.secunda + t2.secunda;
    while(rezultat.secunda !=0)
    {
        if(rezultat.secunda > 60)
        {
            rezultat.minut ++;
            rezultat.secunda -= 60;
        }
    }
    rezultat.minut = t1.minut+ t2.minut;
    while(rezultat.minut !=0)
    {
        if(rezultat.minut > 60)
        {
            rezultat.ora ++;
            rezultat.minut -= 60;
        }
    }
    rezultat.ora = t1.ora + t2.ora;

};
main()
{
    struct timp t1, t2, suma;
    scanf("%d", &t1.ora);
    scanf("%d", &t1.minut);
    scanf("%d", &t1.secunda);
    scanf("%d", &t2.ora);
    scanf("%d", &t2.minut);
    scanf("%d", &t2.secunda);
    suma = functie(t1,t2);
    printf("%d: %d: %d ", suma.ora, suma.minut, suma.secunda);

}
