#include<bits/stdc++.h>
using namespace std;
int k,m,n,i;
long long f[961100];
int main()
{
	cin>>k;
	f[1]=f[2]=1;
	for(i=3;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=k) break;
	}		
	cout<<"m="<<f[i-2]<<"\nn="<<f[i-1];
	return 0;
}
