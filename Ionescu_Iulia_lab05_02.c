#include<stdio.h>
/*Ionescu Iulia 313AC*/
int perfect(int nr)
{
    int sd = 0, i;
    for(i= 1; i <= nr/2 ; i++)
    {
        if( nr % i == 0)
        {
            sd += i;
        }
    }
    if( sd == nr )return 1;
    else return 0;

}
main()
{
    int nr;
    printf("Citeste nr de la tastatura:");
    scanf("%d", &nr);
    printf("%d", perfect(nr));
}
