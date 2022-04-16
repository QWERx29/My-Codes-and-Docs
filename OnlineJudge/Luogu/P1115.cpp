#include<iostream>
using namespace std;
int a[200050],b[200050],c[200050],n,minx=0,maxx=-999999;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		c[i]=c[i-1]+a[i];
	}
	b[1]=a[1];minx=min(0,c[1]);
	for(int i=2;i<=n;i++)
	{
		b[i]=c[i]-minx;
		minx=min(minx,c[i]);
	}
	for(int i=1;i<=n;i++) maxx=max(maxx,b[i]);
	cout<<maxx<<endl;
}
