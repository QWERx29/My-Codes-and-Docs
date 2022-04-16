#include<bits/stdc++.h>
using namespace std;
void convert(int m,int n)
{
	int i;
	int flag_odd=0;
	if(m%2==1) flag_odd=1;
	if(m==1&&n==0) cout<<"2(0)";
	else if(m==1&&n==1) cout<<"2";
	else if(m==1&&n==2) cout<<"2(2)";
	else if(m>1) 
		{
			if(flag_odd)
			{
				convert(m/2,n+1);
				cout<<"+";
				convert(1,n);
			}
			else 
			 	convert(m/2,n+1);
		}
	else if(m==1&&n>=3)
	{
		cout<<"2(";
		convert(n,0);
		cout<<")";
	}
} 
int main()
{
	int i,k,m;
	cin>>m;
	convert(m,0);
	return 0;
}

