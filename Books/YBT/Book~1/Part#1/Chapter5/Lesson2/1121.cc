#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],m,n,sum;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            if(i==1||i==m||j==1||j==n) sum+=a[i][j];
    }
    cout<<sum;
    return 0;
}