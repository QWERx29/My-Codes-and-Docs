#include<bits/stdc++.h>
using namespace std;
double f[151][151],m[151],minn,r,tmp,x[151],y[151],maxn=1<<30;
double dist(int i,int j)
{
	return sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
}
int n;
char c;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c;
			if(i==j) f[i][j]=0;
			else if(c=='1') f[i][j]=dist(i,j);
			else f[i][j]=maxn;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					if(f[i][k]<maxn-1&&f[k][j]<maxn-1)
					{
						if(f[i][j]>f[i][k]+f[k][j])
							f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
	}
//	memset(m,0,sizeof(m));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]<maxn-1&&m[i]<f[i][j]) m[i]=f[i][j];
		}
	}
	minn=1<<30;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&f[i][j]>maxn-1)
			{
				tmp=dist(i,j);
				if(minn>m[i]+m[j]+tmp) minn=m[i]+m[j]+tmp;
			}
		}
	}
	r=0;
	for(int i=1;i<=n;i++) 
	{
		if(m[i]>minn) minn=m[i];
	}
	printf("%.6lf",minn);
	return 0;
}

