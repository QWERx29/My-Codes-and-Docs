#include<bits/stdc++.h>
using namespace std;
const int N=96110;
int n,m,f[N],w[N],v[N];
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=w[i];j--) 
            f[j]=max(f[j],f[j-w[i]]+w[i]*v[i]);
    }
    cout<<f[m];
    return 0;
}
