#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a=0;
	a+=m*2;
	for(int i=m+1;i<=n;i++)
	{
		a+=i;
	}
	cout<<a<<endl;
	return 0;
}
