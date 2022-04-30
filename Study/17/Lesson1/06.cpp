#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,b[N],f[N],ans=1;
struct city
{
    int s,e;
}a[N];
bool cmp(const city &q,const city &w) {return w.s>q.s;}
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].e;
    sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
	        if(a[i].e>a[j].e)  f[i]=max(f[i],f[j]+1);
		ans=max(f[i],ans);
	}
	cout<<ans+1<<endl;
	return 0;
}
