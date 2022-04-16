#include<bits/stdc++.h>
using namespace std;
int h[110],hm,n; 
int main()
{
	for(int i=1;i<=10;i++)
	{
		cin>>h[i];
	}
	cin>>hm;
	for(int i=1;i<=10;i++)
	{
		if(h[i]<=hm+30) n++;
	}
	cout<<n;
	return 0;
}

