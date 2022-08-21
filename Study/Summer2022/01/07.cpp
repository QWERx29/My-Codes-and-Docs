#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,q;
struct node{
	int a,b,w;
	bool operator < (const node& x) const { return w<x.w; }
}v[N];
struct query{
	int k,id;
	bool operator < (const query& x) const { return k<x.k; }
}u[N];
int f[N],s[N],ans[N],cur;
inline void init(int n)
{
	for(int i=1;i<=n;i++) 
		f[i]=i,s[i]=1;
}
int search(int x){ return x==f[x]?x:f[x]=search(f[x]); }
int F(int q){ return q*(q-1)/2;}
inline void merge(int x,int y)
{
	x=search(x),y=search(y);
	if(x==y) return ;
	cur-=F(s[x])+F(s[y]);
	f[x]=y,s[y]+=s[x];
	cur+=F(s[y]);
}

int main()
{
	cin>>n>>m>>q;
	init(n);
	for(int i=1;i<=m;i++) cin>>v[i].a>>v[i].b>>v[i].w;
	for(int i=1;i<=q;i++) cin>>u[i].k,u[i].id=i;
	sort(v+1,v+m+1);
	sort(u+1,u+q+1);
	for(int i=1,j=0;i<=q;i++)
	{
		while(j+1<=m&&v[j+1].w<=u[i].k) 
			j++,merge(v[j].a,v[j].b);
		ans[u[i].id]=cur;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}