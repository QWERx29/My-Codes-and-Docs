#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110],b[110][110],t;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==b[i][j]) t++;
    printf("%.2lf",100.0*t/(n*m));
    return 0;
}