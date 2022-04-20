#include<bits/stdc++.h>
#define N 96110
#define ll long long
ll l,r,cnt; 
ll f(ll q)
{
	ll w=1;
	while(q!=1)
	{
		if(q%2==0) q/=2;
		else q=3*q+1;
		w++;
	}
	return w;
}
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
//	freopen("100.in","r",stdin);
//	freopen("100.out","w",stdout);
	while(scanf("%d%d",&l,&r)==2)
	{
		cout<<l<<" "<<r<<" ";
		if(r<l) swap(l,r);
		cnt=1;
		for(ll i=l;i<=r;i++)
		{
			cnt=max(cnt,f(i));
		}
		cout<<cnt<<endl;
	}
	return 0;
}

