#include<iostream>
using namespace std;
int main()
{
    int nr, i, n = 1;
    cout<<"Introduceti numarul pentru care calculati factorialul de la tastatura\n";
    cin>>nr;
    if(nr < 0)
        cout<<"Numarul nu este natural!";
    for(i=1; i<=nr; i ++ )
        n *= i;
    if(nr ==0) n=1;
    cout<<"Factorialul este:\n";
    cout<<n;
    return 0;
}
