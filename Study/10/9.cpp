#include<bits/stdc++.h>
using namespace std;
int n,a[961100],r[961100],j,k;
int ans;
void mergesort(int s,int t)
{
	if(s==t) return;
	int mid=(s+t)/2;
	mergesort(s,mid);
	mergesort(mid+1,t);
	int i=s,j=mid+1,k=s;
	while(i<=mid&&j<=t)
	{
		if(a[i]<=a[j])
		{
			r[k]=a[i];k++;i++;
		}
		else
		{
			r[k]=a[j];k++;j++;
			ans+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		r[k]=a[i];k++;i++;
	}
	while(j<=t)
	{
		r[k]=a[j];k++;j++;
	}
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
