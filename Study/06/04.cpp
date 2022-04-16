#include<bits/stdc++.h>
using namespace std;
bool check(int n,int d)
{
	int m;
	while(n!=0)
	{
		m=n%10;
		if(m==d) return true;
		else n/=10;
	}
	return false;
}
int main()
{
	int n,d;
	cin>>n>>d;
	if(check(n,d)==1) cout<<"true";
	else cout<<"false";
	return 0;
}

