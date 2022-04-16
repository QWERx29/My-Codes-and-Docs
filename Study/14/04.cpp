#include<bits/stdc++.h>
using namespace std;
int a[10086],l[10086];
int main()
{
	int n=1;
	while(cin>>a[n]) n++;
	int k=1;
	int p,j=1;
	l[k]=a[1]; 
	for(int i=2;i<=n;i++) 
	{
		p=0;
		for(int j=1;j<=k;j++)
		{
			if(l[j]>=a[i])
			{
				if(p==0) p=j;
				else if(l[p]>l[j]) p=j;
			}
		}
		if(p==0)
		{
			k++;
			l[k]=a[i];
		}
		else l[p]=a[i];
	}
	cout<<k<<endl;
	return 0;
}
