#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    FILE *sursa, *dest;
    char buffer[1000];
    size_t n;
    if(argc !=3)
    {
        fprintf(stderr, "cp. Sintaxa este :cp sursa destinatie");
        exit(1);
    }
    if((sursa=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr, "cp. Eroare deschidere fisier %s\n", argv[1]);
        exit(1);
    }
    if((dest=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr, "cp. Eroare deschidere fisier %s\n", argv[2]);
        exit(1);
    }
    n=fread(buffer,1,1000,sursa);
    while(n>0)
    {
        fwrite(buffer,1,n,dest);
        n=fread(buffer,1,1000,sursa);
    }
    fclose(sursa);
    fclose(dest);
    return 0;
}
