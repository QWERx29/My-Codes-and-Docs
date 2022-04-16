#include <bits/stdc++.h>
int m,t,s;
using namespace std;
int main() 
{
    cin>>m>>t>>s;
    if(t==0) 
	{
		cout<<0;
		return 0;
	}
	else
	{
		if(s%t==0) cout<<max(0,m-s/t);
		else cout<<max(0,m-s/t-1);
		return 0;
	}
}
