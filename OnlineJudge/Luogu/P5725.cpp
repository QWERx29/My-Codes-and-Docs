#include<bits/stdc++.h>
using namespace std;
int n,t,q;
int main()
{
	cin>>n;
	for(int i=1;i<=pow(n,2);i++)
	{
		if(i<10) cout<<0;
		cout<<i;
		if(i%n==0) cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<n-i;k++) cout<<"  ";
		for(int j=1;j<=i;j++)
		{
			++q;
			
			if(q<10) cout<<0;
			cout<<q;
		}
		cout<<endl;
	}
	return 0;
}

