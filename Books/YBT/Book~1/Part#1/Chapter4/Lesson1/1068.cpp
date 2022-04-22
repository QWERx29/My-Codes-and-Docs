#include<bits/stdc++.h>
using namespace std;
int n,m,sum,t;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==m) sum++;
    }
    cout<<sum;
    return 0;
}