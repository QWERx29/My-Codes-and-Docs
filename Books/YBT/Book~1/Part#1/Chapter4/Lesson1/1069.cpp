#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        ans*=n;
    }
    cout<<ans;
    return 0;
}