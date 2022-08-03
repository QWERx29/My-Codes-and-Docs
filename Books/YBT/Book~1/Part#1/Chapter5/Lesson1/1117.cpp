#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	int a[20000];
    for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) 
			if(a[i]==a[j]) a[j]=0;
	}
	for(int i=1;i<=n;++i)
		if(a[i]!=0)	cout<<a[i]<<" ";
	return 0;
}