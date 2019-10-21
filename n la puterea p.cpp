#include<iostream>
using namespace std;
int main()
{
    int n, p,i, rez = 1;
    cout<<"Introduceti numarul n:\n";
    cin>>n;
    cout<<"Introduceti exponentul p:\n";
    cin>>p;
    for(i=1; i <=p; i++)
        rez *= n;

    if (p ==0)rez=1;

    cout<<"n^p ="<<rez;
    return 0;
}
