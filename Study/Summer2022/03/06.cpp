#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int c[N],n,q;
int tmp,a,b;
string op;

inline int query(int x)
{
	int res=0;
	for(;x;x-=x&-x) res+=c[x];
	return res;
}
inline void update(int x,int delta)
{
	for(;x<=n;x+=x&-x) c[x]+=delta;
}

int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>tmp,update(i,tmp);
	for(int i=1;i<=q;i++)
	{
		cin>>op>>a>>b;
		if(op=="Query") cout<<query(b)-query(a-1)<<endl; //a=l,b=r
		else update(a,b);  //a=x,b=c
	}
	return 0;
}