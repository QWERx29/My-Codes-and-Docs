#include<bits/stdc++.h>
using namespace std;
const int MAXN=10086;
struct node{ 
	int x, y;
}point[MAXN];
double ans,dis[MAXN];
bool vis[MAXN];
int n;
double calc(int a,int b) 
{
    return sqrt((double)(point[a].x-point[b].x)*(point[a].x-point[b].x)+(double)(point[a].y-point[b].y)*(point[a].y-point[b].y));
}
int main() 
{
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) 
	{
        cin>>point[i].x>>point[i].y;
        dis[i]=1e8;
    }
    int pos; dis[1] = 0;
    for(int i=1;i<=n;i++) 
	{
        double minn=1e8;
        for(int j=1;j<=n;j++) 
        {
        	if(!vis[j]&&dis[j]<minn) 
			{
            	minn=dis[j]; 
				pos=j;
        	}
		}
		ans+=minn;
		vis[pos]=true;
        for(int j=1;j<=n;j++) 
		{
            double d=calc(pos,j);
            if(d<dis[j]) dis[j]=d;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
