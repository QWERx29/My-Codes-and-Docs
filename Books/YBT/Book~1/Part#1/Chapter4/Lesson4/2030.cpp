#include<iostream>
using namespace std;
int main()
{
	int n,m,sum=0;
	bool flag=false;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) {flag=false; break;}
			else flag=true;
		}
		if(flag==true) {cout<<i<<"\n"; sum++;}
	}
	return 0;
}
