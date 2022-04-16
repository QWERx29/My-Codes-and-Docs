#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},sum,x;
int match(int n)
{
	int q=0;
	for(int i=n;i!=0;i/=10) q+=a[i%10];
	if(n==0) q+=a[0];
	return q;
}
int main()
{
	cin>>x;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			if(match(i)+match(j)+match(i+j)+4==x) sum++;
		}
	}
	cout<<sum;
}
