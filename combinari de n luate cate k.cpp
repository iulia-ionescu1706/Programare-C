#include<iostream>
using namespace std;
int main()
{
    int n, i,j,m, k, factn =1, factk = 1, factnk = 1 , rez;
    cout<<"n = \n";
    cin>>n;
    cout<<"k = \n";
    cin>>k;
    if(k>n || n ==0 || k ==0)
    {
        cout<<"Ati introdus o combinatie incorecta de numere!\n";
        return 0;
    }
    for(i=1; i<= n; i++)
        factn *= i;
    for(j=1; j<=k; j++)
        factk *= j;
    for(m=1; m<= n-k; m++)
        factnk *= m;

    rez = factn / (factk * factnk);
    cout<<"Combinari de"<<n<<"luate cate"<<k<<"egal cu"<<rez;
    return 0;

}
