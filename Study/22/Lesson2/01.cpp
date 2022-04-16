#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[110][3],n,x,y,m,s,e;
double f[110][110]; 
//int pre[110][110];
/*
void print(int x)
{
	if(pre[s][x]==0) return ;
	print(pre[s][x]);
	printf("->%d",x);
}
*/
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2];
	cin>>m;
	memset(f,0x7f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[y][x]=f[x][y]=sqrt(pow(double(a[x][1]-a[y][1]),2)+pow(double(a[x][2]-a[y][2]),2));
//		pre[x][y]=x;
//		pre[y][x]=y;
	}
	cin>>s>>e;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((i!=j)&&(i!=k)&&(j!=k)&&(f[i][j]>f[i][k]+f[k][j])) 
				{
					f[i][j]=f[i][k]+f[k][j];
//					pre[i][j]=pre[k][j];
				}
					
			}
		}
	}
	printf("%.2lf\n",f[s][e]);
//	printf("%d",s);
//	print(e);
	return 0;
}

