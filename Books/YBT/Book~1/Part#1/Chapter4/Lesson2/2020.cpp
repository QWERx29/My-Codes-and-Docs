#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main ()
{
    cin>>m;
    while(sum<m)
    {
        n++;
        sum+=n;
    }
    cout<<n;
    return 0;
}