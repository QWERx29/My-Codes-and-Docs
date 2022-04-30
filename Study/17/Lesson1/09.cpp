#include<bits/stdc++.h>
using namespace std;
int f[25][25],val[25][25],m,n,maxn;
void show(int q,int w)
{
    int k;
    if(q==0) return ;
    for(k=0;k<=w;k++)
    {
        if(maxn==f[q-1][k]+val[q][w-k])
        {
            maxn=f[q-1][k];
            show(q-1,k);
            cout<<q<<" "<<w-k<<endl;
            break;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>val[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            maxn=0;
            for(int k=0;k<=j;k++)
                maxn=max(maxn,f[i-1][k]+val[i][j-k]);
            f[i][j]=maxn;
        }
    }
    cout<<f[n][m]<<endl;
    show(n,m);
    return 0;
}