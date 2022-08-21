#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2022;

int n,m,a[N],f[N],g[N];

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=a[i];j--)
            f[j]=(f[j]+f[j-a[i]])%10;
    }
    for(int i=1;i<=n;i++)
    {
        memcpy(g,f,sizeof(g));
        for(int j=a[i];j<=m;j++) g[j]=((g[j]-g[j-a[i]])%10+10)%10;
        for(int j=1;j<=m;j++) cout<<g[j];
        cout<<endl;
    }
}