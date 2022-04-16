// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		if((m*n)%i==0&&gcd(i,(m*n)/i)==m)
			ans++;
	}
	cout<<ans;
}
