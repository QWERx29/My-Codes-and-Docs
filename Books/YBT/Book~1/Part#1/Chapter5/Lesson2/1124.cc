#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],b[110][110],c[110][110];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>b[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[i][j]=a[i][j]+b[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}