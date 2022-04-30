#include<bits/stdc++.h>
using namespace std;
int n,a[110][110],r[110],f[110],x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    memset(f,0x7f,sizeof(f));f[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        for(x=i+1;x<=n;x++)
        {
            if(a[i][x]>0&&f[x]!=0x7f7f7f7f&&f[i]>f[x]+a[i][x]) {f[i]=f[x]+a[i][x];r[i]=x;}
        }
    }
    cout<<"minlong="<<f[1]<<endl;
    x=1;
    while(x!=0) {cout<<x<<" ";x=r[x];}
    return 0;
}