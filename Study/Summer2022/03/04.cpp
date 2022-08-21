#include<bits/stdc++.h>
using namespace std;
const int N=1000005;

struct node{
	int c[2];
}a[N*32];
int rot=1,tot=1;
int n,x,ans;

inline void insert(int x)
{
	int pos=rot,val;
	for(int i=31;i>=0;i--)
	{
		val=(x>>i)&1;
		if(a[pos].c[val]==0) a[pos].c[val]=++tot;
		pos=a[pos].c[val];
	}
}
inline int query(int x)
{
	int pos=rot,val,res=0;
	for(int i=31;i>=0;i--)
	{
		val=((x>>i)&1)^1;
		if(!a[pos].c[val]) pos=a[pos].c[val^1];
		else pos=a[pos].c[val],res=res|(1<<i);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		insert(x);
		ans=max(ans,query(x));
	}
	cout<<ans;
	return 0;
}