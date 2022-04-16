#include<bits/stdc++.h>
using namespace std;
int n,sum[100010],q[100010],h[100010];
struct node
{
    int s,a;
}v[100010];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{	
	cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i].s;
    for(int i=1;i<=n;i++) cin>>v[i].a;
    sort(v+1,v+1+n,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+v[i].a; 
    for(int i=1;i<=n;i++) q[i]=max(q[i-1],2*v[i].s);
    for(int i=n;i>=1;i--) h[i]=max(h[i+1],2*v[i].s+v[i].a);
    for(int i=1;i<=n;i++) cout<<max(sum[i]+q[i],sum[i-1]+h[i])<<endl;
    return 0;
}
