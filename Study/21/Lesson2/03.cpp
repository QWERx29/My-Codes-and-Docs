#include<bits/stdc++.h>
using namespace std;
int a[100860],tmp,n,i;
void heap(int r[],int nn,int ii)
{
	int x,i=ii,j;
	x=r[ii];
	j=2*i;
	while(j<=nn)
	{
		if(j<nn&&r[j]<r[j+1]) j++;
		if(x<r[j])
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
		else break;
	}
	r[i]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;i++)  cin>>a[i];
	for(i=n/2;i>=1;i--) heap(a,n,i);
	for(i=n;i>=1;i--)
	{
		//cout<<a[1]<<" ";
		swap(a[1],a[i]);
		heap(a,i-1,1);
	 } 
	 for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
