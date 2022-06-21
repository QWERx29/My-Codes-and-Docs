#include<bits/stdc++.h>
using namespace std;
const int N=250;
int w[N],c[N],p[N],f[N],m,n;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>w[i]>>c[i]>>p[i];
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0)
        {
            for(int j=w[i];j<=m;j++)
                f[j]=max(f[j],f[j-w[i]]+c[i]);
        }
        else 
        {
            for(int j=1;j<=p[i];j++)
            {
                for(int k=m;k>=w[i];k--)
                    f[k]=max(f[k],f[k-w[i]]+c[i]);
            }
        }
    }
    cout<<f[m];
    return 0;
}