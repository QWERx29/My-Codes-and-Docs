#include<bits/stdc++.h>
using namespace std;
const int N=96110;
int w[N],c[N],f[N],m,n,nn;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y,z,t=1;
        cin>>x>>y>>z;
        while(z>=t)
        {
            w[++nn]=x*t;
            c[nn]=y*t;
            z-=t;
            t*=2;
        }
        w[++nn]=x*z;
        c[nn]=y*z;
    }
    for(int i=1;i<=nn;i++)
    {
        for(int j=m;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+c[i]);
    }
    cout<<f[m];
    return 0;
}