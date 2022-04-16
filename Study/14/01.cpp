#include<bits/stdc++.h>
using namespace std;
int n,r,minn,k;
int s[10086],a[10086];
int main()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;++i)
	{
		k++;
		if(k==r+1) k=1;
		s[k]+=a[i];
		minn+=s[k];
	}
	cout<<minn;
	return 0;
}

