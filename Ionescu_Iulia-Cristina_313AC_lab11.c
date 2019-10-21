#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char s[100]="something random";
char sample[]="abcdefghijklmnopqrstuvwxyz ";

int test(char c,char t)
{
    return abs((int)c-(int)t);
}
char gena(char c,char b)
{
	int r;
    char k=c;
    int first=test(k,c);
    if(c!=b)
    {
        r=rand()%strlen(sample);
    }
    c=sample[r];
    int second=test(k,c);
    if(second<first)
    {
        return k;
    }
    else
    {
        return c;
    }
}

void crucis(char a[],char b[])
{
	char s[100];
	int i;
	for(i=0; i<strlen(a);i++)
	{
		a[i]=test(a[i],b[i]);
	}
}
void mutatie(char k[])
{
    int j;
	 for(j=0; j<strlen(s);j++)
        {
            k[j]=gena(k[j],s[j]);
        }

}
int forma(char k[])
{
	int suma=-1;
	int ok=0;
	int i;
	for(i=0;i<strlen(k);i++)
	{
		ok=1;
		suma+=abs(s[i]-k[i]);
	}
	if(strcmp(k,s)==0)
	{
	return 0;
	}
	return suma;
}
int main()
{
    int l,i,om, ok;
    char best[100];
    char k[100]="aaaaaaaaaaaaaaaa",k2[100]="bbbbbbbbbbbbb";
   for(l=0;l<100000;l++)
    {
    for(i=0;i<200;i++)
    {
    	mutatie(k);
        int rob=forma(k);
        if(rob<ok&&rob!=-1)
        {
        	ok=rob;
        	strcpy(best,k);
		}
		if(rob==0)
		{
			printf("%s\n",k);
			printf("Solutie gasita ");
			return 0;
		}

    }
    	for(om=0;om<777;om++)
    	{
    	mutatie(k);
    	crucis(k,best);
        }
    	if(forma(k)<ok)
    	{
    		ok=forma(k);
    		strcpy(best,k);
		}

     printf("%s\n",best);

}
  	printf("%s\n",s);
  	printf("%s",sample);



   mutatie(k);
    for( i=0;i<3000;i++)
    {
    	mutatie(k2);
    	crucis(k,k2);

    	printf("%s\n",k);
    	printf("%s\n",s);
    	if(forma(k)==0)
    	{
    		printf("solutia");
		}
	}
    return 0;
}

