#include<stdio.h>
/*Ionescu Iulia-313AC*/

char ord(int a, int b, int c)
{
    if(a<b && b<c)
        return 'C';
    if(a>b && b>c)
        return 'D';
    if(a==b && b==c)
        return 'I';
    if((a>b && b<=c)||(a <= b && b>c))
        return 'N';
}

main()
{
    int nr1, nr2, nr3;
    printf("Introduceti numerele de comparat");
    scanf("%d %d %d", &nr1, &nr2, &nr3);
    printf("%c", ord(nr1, nr2, nr3));
}




//Sa se scrie şi să se testeze o funcţie C care, analizând 3 valori numerice
// întregi, să verifice dacă acestea sunt ordonate crescător, descrescător,
// sunt identice sau sunt neordonate (ţinând cont de ordinea în care au fost
//precizate). Rezultatul va fi furnizat ca valoare de tip caracter: ’C’, ’D’,
// ’I’ sau ’N’. Se recomandă testarea funcţiei în cadrul unui program C care
// să permită execuţia în buclă, pentru mai multe seturi de câte 3 valori
//  introduse de la tastatură (a se consula exemplul de la curs – slide
//Cap6_3_C_15_2.png). Altă variantă de enunţ: rezultatul va fi furnizat ca
//valoare de tip întreg, cu semnificaţie prestabilită.
