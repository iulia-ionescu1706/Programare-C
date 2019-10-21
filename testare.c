#include<stdio.h>

struct elev
{
    int varsta;
    char nume[20];
};
main()
{
    int i;
    struct elev e1,e2;
    struct elev vector[4];
    printf("Nume:");
    fflush(stdin);
    gets(e1.nume);
    printf("Varsta:");
    scanf("%d",&e1.varsta);
    printf("Nume:");
    fflush(stdin);
    gets(e2.nume);
    printf("Varsta:");
    scanf("%d",&e2.varsta);
    vector[0]=e1;
    vector[1]=e2;
    for(i=0;i<2;i++)
        printf("%d\t%s\n",vector[i].varsta, vector[i].nume);
}
