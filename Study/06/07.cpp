#include<bits/stdc++.h>
using namespace std;
bool q(int n)
{
	bool flag=true;
	if(n==1) return false;
	for(int j=2;j*j<=n;j++)
	{
		if(n%j==0) {flag=false; break;}
		else flag=true;
	}
	if(flag==true) return true;
	else return false;
}
int main()
{
	int n;
	cin>>n;
	if(q(abs(n))==true) cout<<"yes";
	else cout<<"no";
	return 0;
}

