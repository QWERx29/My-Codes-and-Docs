#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int a[N],b[N];
int k1=1,k,f1=1,f2=1,r1,r2;
int m,n;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) a[i]=i;
	for(int i=1;i<=n;i++) b[i]=i;
	cin>>k;
	r1=m;r2=n;
	while(k1<=k)
	{
		cout<<a[f1]<<" "<<b[f2]<<endl;
		r1++;a[r1]=a[f1];f1++;
		r2++;b[r2]=b[f2];f2++;
		k1++;
	}	
	return 0;
}

