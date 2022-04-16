#include<bits/stdc++.h>
using namespace std;
#define N 10086
int n,m,dis[N][N],s1=N,ans;
char du[N],a[N];
void dfs(int i)
{
    for(int j=1;j<=150;j++)
    {
		if(dis[i][j]>0)
		{
			dis[i][j]--;
            dis[j][i]--;
            dfs(j);
        }
	}
	a[++ans]=i;
    return ;
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        dis[s[0]][s[1]]++;
        dis[s[1]][s[0]]++;
        du[s[0]]++;
        du[s[1]]++;
    } 
    int cnt=0,h=0;
    for(int i=1;i<=150;i++)
	{
		if(du[i]&1)
		{
            cnt++;
            if(!h)h=i;
        }
	}
    if(!h)
	{
    	for(int i=0;i<150;i++)
    	{
    		if(du[i])
			{
				h=i;
				break;
			}
		}     
	}   
    if(cnt&&cnt!=2)
	{
    	cout<<"No Solution";
    	return 0;
    }
    dfs(h);
    if(ans<m+1)
	{
    	cout<<"No Solution";
    	return 0;
    }
    for(int i=ans;i>=1;i--) printf("%c",a[i]);
    return 0;
}
