#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int n,m,f[N],w[N],c[N];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=w[i];j--) 
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    }
    cout<<f[m];
    return 0;
}
