#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+500;

int c[N],d[N],n,q;
int tmp,a,b,w,op,x;

inline int query(int x,int *o)
{
	int res=0;
	for(;x;x-=x&-x) res+=o[x];
	return res;
}
inline void update(int x,int delta,int *o)
{
	for(;x<=n;x+=x&-x) o[x]+=delta;
}
inline int cal(int x)
{
	if(x==0) return 0;
	return (x+1)*query(x,d)-query(x,c);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		update(i,tmp-w,d);
		update(i,(tmp-w)*i,c);
		w=tmp;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>op>>a>>b;
		if(op==1) 
		{
			cin>>x;
			update(a,x,d),update(a,x*a,c);
			update(b+1,-x,d),update(b+1,-x*(b+1),c);
		}
		else cout<<cal(b)-cal(a-1)<<endl;
	}
	return 0;
}