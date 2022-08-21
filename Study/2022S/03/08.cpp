#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int c[N],n,q;
int l,r,x,op;

inline int query(int x)
{
	int res=0;
	for(;x;x-=x&-x) res^=c[x];
	return res;
}
inline void update(int x)
{
	for(;x<=n;x+=x&-x) c[x]^=1;
}

int main()
{
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>op;
		if(op==1) 
		{
			cin>>l>>r;
			update(l),update(r+1);
		}
		else 
		{
			cin>>x;
			cout<<query(x)<<endl;
		}
	}
	return 0;
}