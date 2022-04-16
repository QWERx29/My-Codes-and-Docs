#include<bits/stdc++.h>
using namespace std;
int n,a[500010],r[500010],j,k;
long long ans;
void mergesort(int s,int t)
{
	if(s==t) return;
	int mid=(s+t)/2,i=s,j=mid+1,k=s;
	mergesort(s,mid);
	mergesort(mid+1,t);
	while(i<=mid&&j<=t)
	{
		if(a[i]<=a[j]) r[k++]=a[i++];
		else
		{
			r[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid) r[k++]=a[i++];
	while(j<=t)	r[k++]=a[j++];
	for(int i=s;i<=t;i++) a[i]=r[i];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	mergesort(0,n-1);
	cout<<ans;
	return 0;
}
