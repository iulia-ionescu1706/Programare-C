#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"Cititi de la tastatura numarul caruia vreti sa ii calculati tabla inmultirii:\n";
    cin>>n;
    for(i=1; i<= n; i++)
        cout<<n<<"*"<<i<<"="<<n*i<<endl;

    return 0;

}
