#include<bits/stdc++.h>
using namespace std;
long long n,a[1000086],k;
void quicksort(long long l,long long r)
{
	long long i,j,mid;
	i=l;j=r;
	mid=a[(l+r)/2];
	do
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}while(i<=j);
	if(l<j) quicksort(l,j);
	if(i<r) quicksort(i,r);
}
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i];
	quicksort(0,n-1);
	for(long long i=0;i<=n;i++)
	{
		k++;
		if(a[i]!=a[i+1])
		{
			cout<<a[i]<<" "<<k<<endl;
			k=0;
		} 
		
	}
	return 0;
}
