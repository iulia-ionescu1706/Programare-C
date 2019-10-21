#include<stdio.h>
#include<string.h>

char concatenare(char sir1[], char sir2[], char sir3[], char sir4[])
{
    int i,j,k,l=1;
    for(i= 0; i<= strlen(sir1)-1; i++)
        sir4[l++] = sir1[i];
    l=strlen(sir4);

    for(j=0; j<= strlen(sir2)-1; j++)
       sir4[l++] = sir2[j];
    l=strlen(sir4);

    for(k=0; k<= strlen(sir3)-1; k++)
        sir4[l++] = sir3[k];
}

main()
{

    char sir1[20], sir2[20], sir3[20], sir4[70];
    fflush(stdin);

    gets(sir1);
    fflush(stdin);

    gets(sir2);
    fflush(stdin);

    gets(sir3);
    fflush(stdin);

    concatenare(sir1,sir2,sir3,sir4);
    puts(sir4);
    /*Varianta folosind functie de biblioteca: */
    /*char sir1[50], sir2[15], sir3[15];
    gets(sir1);
    gets(sir2);
    gets(sir3);
    strcat(sir1, sir2);
    puts(sir1);
    puts(sir2);
    strcat(sir1, sir3);
    puts(sir1);
    puts(sir3);   */
}
