// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
struct vol
{
	int num,res;
}a[5005];
bool cmp(vol x,vol y)
{
    if(x.res>y.res) return 1;
    else if(x.res==y.res)
	{
		if(x.num<y.num) return 1;
  else return 0;
	}
	else return 0;
}
int n,m;
int main()
{
	cin>>n>>m;
	m=floor(m*1.5);
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].res;
	sort(a+1,a+n+1,cmp);
	int q=a[m].res,k=m;
	for(int i=m+1;i<=n;i++)
	{
		if(a[i].res==q) k++;
		else if(a[i].res<q) continue;
	}
	cout<<q<<" "<<k<<endl;
	for(int i=1;i<=k;i++) cout<<a[i].num<<" "<<a[i].res<<endl;
}
