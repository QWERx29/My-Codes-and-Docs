#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n,a,b;
int f[N],v[N];
inline void init(int n) 
{
	for(int i=1;i<=n;i++)
		f[i]=i,v[i]=1;
}
int fnd(int x) { return x==f[x]?x:f[x]=fnd(f[x]); }
inline void uni(int a, int b) 
{
	a=fnd(a),b=fnd(b);
	if(a==b) v[a]=-N;
	else f[a]=b,v[b]+=v[a];
}
int ans=0;
inline bool check(int x) 
{
	x=fnd(x);
	if(v[x]<0) return true;
	return --v[x];
}
int main() 
{
	cin>>n;
    init(n);
	for (int i= 1;i<=n;i++)
		cin>>a>>b,uni(a,b);
	while(check(ans+1))++ans;
	cout<<ans;
    return 0;
}