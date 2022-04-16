#include<bits/stdc++.h>
using namespace std;
bool f[105][105];
int color[105];
int num=0;
int n,k,m;
bool check(int sum)
{
    for(int i=1;i<=sum;i++)
	{
        if(f[i][sum]==true&&color[i]==color[sum]) return false;
    }
    return true;
}
void dfs(int s)
{
    if(s>n)
	{
        num++;
        return;
    }
    for(int i=1;i<=m;i++)
	{
        color[s]=i;
        if(check(s)==true) dfs(s+1);
		else color[s]=0;
    }
}        
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++)
	{
        int x,y;
        cin>>x>>y;
        f[x][y]=true;
        f[y][x]=true;
    }
    dfs(1);
    cout<<num<<endl;
    return 0;
}
