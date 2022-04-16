#include<bits/stdc++.h>
using namespace std;
long long n,a[100086],s=1;


int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	a[n]=-100000;
	for(int i=1;i<n;i++)
	{
		
		if(a[i]==a[i-1]) s++;
		else 
		{
			cout<<a[i-1]<<" "<<s<<endl;
			s=1;
		}
	}
	return 0;
}
