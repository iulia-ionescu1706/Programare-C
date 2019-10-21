#include<stdio.h>
#include<string.h>

main()
{
    char text[100];
    int l,i, nr =0;
    gets(text);
    l = strlen(text);
    strlwr(text);
    for(i=1; i<= l; i++)
    {
        if(text[i]==' ')
        {
            switch(text[i-1])
            {
                case 'a': nr++ ; break;
                case 'e': nr++; break;
                case 'i': nr++; break;
                case 'o': nr++; break;
                case 'u': nr++; break;
            }
             switch(text[i+1])
            {
                case 'a': nr++ ; break;
                case 'e': nr++; break;
                case 'i': nr++; break;
                case 'o': nr++; break;
                case 'u': nr++; break;
            }
        }
    }
    if(nr ==1) printf("%d",nr);
    else   printf("%d",nr/2);
}
