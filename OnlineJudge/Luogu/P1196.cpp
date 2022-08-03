#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
typedef pair<int,int> pii;
int f[N],s[N],d[N];
inline void init(int n) { for(int i=1;i<=n;i++) f[i]=i,s[i]=1,d[i]=0;}
pii find(int x)
{
	if(x==f[x]) return pii(f[x],d[x]);
	pii res=find(f[x]);
	f[x]=res.first,d[x]+=res.second;
	res.second=d[x];
	return res;
}
inline void merge(int x,int y)
{
	pii px=find(x),py=find(y);
	x=px.first,y=py.first;
	d[x]=s[y];
	f[x]=y,s[y]+=s[x];
}
int T;
int main()
{
	
	cin>>T;
	init(T);
	while(T--)
	{
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='M')
			merge(x,y);
		if(op=='C')
		{
			if(find(x).first!=find(y).first) cout<<-1<<endl;
			else cout<<abs(d[x]-d[y])-1<<endl;
		}
	}
}