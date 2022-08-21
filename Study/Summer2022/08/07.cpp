#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MOD=1e9+7;

int n,x,c[6];
int dp[16][16][16][16][16][6];

inline int dfs(int a,int b,int c,int d,int e,int nxt)
{
    if(dp[a][b][c][d][e][nxt]!=-1) return dp[a][b][c][d][e][nxt];
    if(a+b+c+d+e==0) return 1;
    int res=0;
    if(a) res+=(a-(nxt==2))*dfs(a-1,b,c,d,e,1);
    if(b) res+=(b-(nxt==3))*dfs(a+1,b-1,c,d,e,2);
    if(c) res+=(c-(nxt==4))*dfs(a,b+1,c-1,d,e,3);
    if(d) res+=(d-(nxt==5))*dfs(a,b,c+1,d-1,e,4);
    if(e) res+=e*dfs(a,b,c,d+1,e-1,5);
    dp[a][b][c][d][e][nxt]=res%MOD;
    return dp[a][b][c][d][e][nxt];
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x,c[x]++;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(c[1],c[2],c[3],c[4],c[5],0);
    return 0;
}