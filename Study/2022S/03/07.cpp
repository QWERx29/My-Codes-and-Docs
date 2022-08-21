#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int a[N],b[N],n,q;
int l,r,x;
string op;

inline int query(int x)
{
	int res=0;
	for(;x;x-=x&-x) res+=b[x];
	return res;
}
inline void update(int x,int delta)
{
	for(;x<=n;x+=x&-x) b[x]+=delta;
}

int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		cin>>op;
		if(op=="Query") 
		{
			cin>>x;
			cout<<a[x]+query(x)<<endl;
		}
		else 
		{
			cin>>l>>r>>x;
			update(l,x),update(r+1,-x);
		}
	}
	return 0;
}