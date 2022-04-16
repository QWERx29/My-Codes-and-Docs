#include<bits/stdc++.h>
using namespace std;
const int N=961100;
typedef long long ll;
int a[N];
ll s[N],t[N];
bool cmp(const int&x,const int&y)
{
	return x>y;
}
int main()
{
	int n,v,l,q,x;
	ios::sync_with_stdio(false);
	cin>>n>>l>>v;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	s[0]=l;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=0;i<=n;i++) t[i]=s[i]/v+(s[i]%v>0);
	cin>>q;
	while(q--)
	{
		cin>>x;
		if (x>=t[n]) cout<<-1<<endl;
		else cout<<upper_bound(t,t+1+n,x)-t<<endl;
	}
	return 0;
}
