#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
ll sqrt2(ll x){
    ll res=(int)sqrt(x-0.1);
    while(res*res<=x) res++;
   return (int)res-1;
}
int main()
{
	ios::sync_with_stdio(false);
 //   freopen("math3.in","r",stdin);
  //  freopen("test.out","w",stdout);
 	ll n;
 	cin>>n;
 	while(n--)
 	{
 		ll x,y,z,d;
 		cin>>x>>z;
 		if(z%x!=0)
 		{
 			cout<<-1<<endl;
 			continue;
		 }
 		d=sqrt2(__gcd(x*x,z/x));
 		y=z/(x*d);
 		if(z%(x*d)!=0)
 		{
 			cout<<-1<<endl;
 			continue;
		 }
 		if(d==__gcd(x,y)) cout<<y<<endl;
 		else cout<<-1<<endl;
	 }
	return 0;
}

