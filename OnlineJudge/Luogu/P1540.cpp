#include <bits/stdc++.h>
using namespace std;
int a[10000],b[1000],m,n,s=0,j=0;
int xz(int ddd){
	for(int i=1;i<=m;i++)
	{
		if(b[i]==ddd)
		return 0;
	}
	return 1;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		a[i]=-1;
		if(xz(a[i])==1)
		{
			s++;
			if(j==m)
			j=0;
			j++;
			b[j]=a[i];
		}
	}
	cout<<s;
	return 0;
}

