#include<bits/stdc++.h>
using namespace std;
int n,a[10086],b[10086],j,k;
void bucketsort()
{
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		b[k]++;
	}
	for(int i=0;i<=100;i++)
	{
		while(b[i]>0)
		{
			cout<<i<<" ";
			b[i]--;
		}
		
	}
	cout<<endl;
}
int main()
{
	cin>>n;
	bucketsort();
	return 0;
}
