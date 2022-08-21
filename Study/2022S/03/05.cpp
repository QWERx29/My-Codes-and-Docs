#include<bits/stdc++.h>
using namespace std;
const int N=1000005;

struct node{
	int c[2];
}a[N*32];
int rot=1,tot=1;
int n,x,ans,q[N],l[N],r[N],s[N];

inline void clear()
{
	memset(a,0,sizeof(node)*(tot+1));
	rot=tot=1;
}
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
	for(int i=1;i<=n;i++) cin>>q[i];
	clear(),insert(0);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^q[i];
		insert(s[i]);
		l[i]=max(query(s[i]),l[i-1]);
	}
	clear(),insert(0);
	for(int i=n;i>=1;i--)
	{
		s[i]=s[i+1]^q[i];
		insert(s[i]);
		r[i]=max(query(s[i]),r[i+1]);
	}
	for(int i=1;i<=n;i++) ans=max(ans,l[i]+r[i+1]);
	cout<<ans;
	return 0;
}