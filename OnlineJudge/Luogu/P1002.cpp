#include<iostream>
using namespace std;
long long dp[1000][1000],vis[1000][1000];
void horse(int a,int b)
{
    vis[a][b]=1;
    vis[a+2][b+1]=1;
    vis[a+1][b+2]=1;
    vis[a-1][b+2]=1;
    vis[a-2][b+1]=1;
    vis[a-2][b-1]=1;
    vis[a-1][b-2]=1;
    vis[a+1][b-2]=1;
    vis[a+2][b-1]=1;
    return ;
}
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    horse(x,y);
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(vis[i][j]==0)
            {
                if(i==0&&j==0)
                    continue;
                else if(i==0&&j!=0)
                    dp[i][j]=dp[i][j-1];
                else if(i!=0&&j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
