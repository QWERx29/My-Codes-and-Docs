#include<bits/stdc++.h>
using namespace std;
const int N=210;
int f[N],w[N],c[N],g[N][N],n,k;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int t;
        for(int j=i+1;j<=n;j++)
        {
            cin>>t;
            if(t==1) g[i][j]=1;
        }
    }
    f[n]=w[n];
    for(int i=n-1;i>=1;i--)
    {
        int l=0;k=0;
        for(int j=i+1;j<=n;j++) 
        {
            if(g[i][j]==1&&f[j]>l) 
            {
                l=f[j];
                k=j;
            }
        }
        f[i]=l+w[i];c[i]=k;
    }
    k=1;
    for(int i=2;i<=n;i++)
    {
        if(f[i]>f[k]) k=i;
    }
    int maxn=f[k];
    cout<<k;
    k=c[k];
    while(k!=0)
    {
        cout<<" "<<k;
        k=c[k];
    }
    cout<<endl<<maxn;
    return 0;
}