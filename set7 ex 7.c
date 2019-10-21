#include<stdio.h>
#include<string.h>

main()
{
    char text[80],i;
    gets(text);
    for(i=0; i<= strlen(text)-1; i++)
    {    if(text[i]!=' ')
        text[i] = text[i]+1;
    }
    puts(text);
}
