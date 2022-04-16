#include<bits/stdc++.h>
using namespace std;
int js(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)
	{
		sum*=i;
	}
	return sum;
 } 
int main()
{
	int n,m,c;
	cin>>m>>n;
	c=js(m)/(js(n)*js(m-n));
	cout<<c;
	return 0;
}

