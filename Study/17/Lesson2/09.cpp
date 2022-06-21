#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int w[N],c[N],f[N],t,m;
int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++) cin>>w[i]>>c[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    }
    cout<<f[t];
    return 0;
}
