// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,k,w,j,q,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		cin>>k>>w;
		j=k;q=w;
		while(j<n){j*=2;q*=2;}
		while(j>n){j-=k;q-=w;}
		while(j<n){j+=k;q+=w;}
		if(q<ans||ans==0) ans=q;
	}
	cout<<ans;
}
