#include<bits/stdc++.h>
using namespace std;
const int N=510;

int n,m,q;
int c[N][N];
int a,b,x,y,tmp;
string op;

inline int query(int x,int y)
{
	int res=0;
	for(int dx=x;dx;dx-=dx&-dx) 
	{
		for(int dy=y;dy;dy-=dy&-dy)
			res+=c[dx][dy];
	}
	return res;
}
inline void update(int x,int y,int delta)
{
	for(int dx=x;dx<=n;dx+=dx&-dx) 
	{
		for(int dy=y;dy<=m;dy+=dy&-dy)
			c[dx][dy]+=delta;
	}
}

int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++) 
		{
			cin>>tmp,update(i,j,tmp);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>op>>a>>b;
		if(op=="Query") 
		{
			cin>>x>>y;
			cout<<query(b,y)-query(b,x-1)-query(x-1,y)+query(a-1,b-1)<<endl;
		}
		else 
		{
			cin>>x;
			update(a,b,x);
		}
	}
	return 0;
}