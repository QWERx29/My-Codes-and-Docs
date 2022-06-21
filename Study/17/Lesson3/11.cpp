#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int a[N],f[N],n,m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i]=max(f[i-1]+a[i],a[i]);
	for(int i=1;i<=n;i++) m=max(m,f[i]);
	cout<<m;
	return 0;
}