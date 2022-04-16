#include<bits/stdc++.h>
using namespace std;
int n,a[10086],j,k;
void insertsort(int r[])
{
	for(int i=0;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i]) break;
		}
		if(j!=i-1)
		{
			int tmp=a[i];
			for(k=i-1;k>j;k--) a[k+1]=a[k];
			a[k+1]=tmp;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	insertsort(a);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
