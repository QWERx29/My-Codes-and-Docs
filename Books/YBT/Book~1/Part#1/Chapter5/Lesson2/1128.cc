#include<bits/stdc++.h>
using namespace std;
int a[110][110],m,n;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==1||i==1||j==m||i==n) cout<<a[i][j]<<" ";
            else cout<<int(((a[i-1][j]+a[i][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/5.0)+0.5)<<" ";
        }
        cout<<endl;
    }
    return 0;
}