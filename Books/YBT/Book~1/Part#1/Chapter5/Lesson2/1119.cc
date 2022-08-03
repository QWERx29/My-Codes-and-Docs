#include<bits/stdc++.h>
using namespace std;
int a[110][110],n,m;
int main()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++) cin>>a[i][j];
    cin>>m>>n;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(i==n) cout<<a[m][j]<<" ";
            else if(i==m) cout<<a[n][j]<<" ";
            else cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}