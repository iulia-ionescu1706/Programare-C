#include<stdio.h>
#include<math.h>

/*Ionescu Iulia 313AC*/
int delta (int *a, int *b, int *c, int delta)
{

    delta = 0;
    int* p;
    p = &delta;
    *p = ((*b)^2) - (4*(*a)*(*c));
    delta= *p;
    return delta;
}
void rezultat(int *a, int *b, int *c)
{
    int x1, x2, d;
    int* p1;
    int* p2;
    d= delta(&a, &b, &c, d);
    printf("%d\n", d);
    x1 = (- (*b) + sqrt(d))/2*(*a);
    printf("%d\n", x1);

    x2 = (- (*b) - sqrt(d))/2*(*a);
    printf("%d\n", x2);
    p1 = &x1;
    p2 = &x2;
    printf("%d, %d",*p1,*p2);
}


int main()
 {

    int a, b, c, d;
    d =0;
  printf("a=");
  scanf("%d", &a);
  printf("b=");
  scanf("%d", &b);
  printf("c=");
  scanf("%d", &c);
  printf("%d\n", delta(&a,&b,&c,d));
  rezultat(&a,&b,&c);
  return 0;

}
