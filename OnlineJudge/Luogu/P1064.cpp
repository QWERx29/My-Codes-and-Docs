#include<bits/stdc++.h>
using namespace std;
const int N=96110;
int m,n;
int miw[N],mic[N],aiw[N][3],aic[N][3],f[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int v,p,q;
        cin>>v>>p>>q;
        if(q==0)
        {
            miw[i]=v;
            mic[i]=v*p;
        }
    else
        {
            aiw[q][0]++;
            aiw[q][aiw[q][0]]=v;
            aic[q][aiw[q][0]]=v*p;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=miw[i]&&miw[i]!=0;j--)
        {
            f[j]=max(f[j],f[j-miw[i]]+mic[i]);
            if(j>=miw[i]+aiw[i][1]) f[j]=max(f[j],f[j-miw[i]-aiw[i][1]]+mic[i]+aic[i][1]);
            if(j>=miw[i]+aiw[i][2]) f[j]=max(f[j],f[j-miw[i]-aiw[i][2]]+mic[i]+aic[i][2]);
            if(j>=miw[i]+aiw[i][1]+aiw[i][2]) f[j]=max(f[j],f[j-miw[i]-aiw[i][1]-aiw[i][2]]+mic[i]+aic[i][1]+aic[i][2]);
        }
    }
    cout<<f[n];
    return 0;
}