#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int w[N],c[N],f[N],n,m;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=w[i];j<=m;j++)
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    }
    cout<<"max="<<f[m];
    return 0;
}
