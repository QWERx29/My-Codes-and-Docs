#include<bits/stdc++.h>
using namespace std;
int a[961100],b[961100],f[96110000][2];
int n,m;
void bfs(int x)
{
	int begin=1,end=1;
	b[x]=1;
	f[begin][0]=x;f[begin][1]=0;
	end++;
	while(begin<end)
	{
		int x1=f[begin][0];
		int ans=f[begin][1];
		if(x1==m)
		{
			cout<<ans<<endl;
			return ;
		}
		for(int i=0;i<3;i++)
		{
			int x3;
			if(i==2) x3=x1*2;
			if(i==0) x3=x1-1;
			if(i==1) x3=x1+1;
			if(x3>=0&&x3<100001&&b[x3]==0)
			{
				b[x3]=1;
				f[end][0]=x3;
				f[end][1]=ans+1;
				end++;
			}
		}
		begin++;
	}
}
int main()
{
	cin>>n>>m;
	bfs(n);
    return 0;
}

