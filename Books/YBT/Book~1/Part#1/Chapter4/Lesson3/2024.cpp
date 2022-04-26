#include<bits/stdc++.h>
using namespace std;
int n,m=1,i=1;
int main()
{
    cin>>n;
    do
    {
        m=(m*1992)%100;
        i++;
    }while (i<=n);
    cout<<m;
    return 0;
}