#include<bits/stdc++.h>
using namespace std;
int n,m;
int main ()
{
    cin>>m>>n;
    while(m!=0)
    {
        if(m<n) swap(m,n);
        m%=n;
    }
    cout<<n;
    return 0;
}