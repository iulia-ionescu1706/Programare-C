#include<stdio.h>

/*Ionescu Iulia 313AC*/
int palindrom(int n)
{
    int inv = 0;
    int nr = n;
    while(n)
    {
        inv *= 10;
        inv = inv + n%10;
        n /= 10;
    }
    if (nr == inv)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 main()
{
    int nr;
    printf("Introduceti nr:");
    scanf("%d", &nr);
   printf("%d", palindrom(nr));

}
