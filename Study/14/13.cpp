#include<iostream>
#include<algorithm>
using namespace std;
int s[100860],t[100860];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			t[i]=s[i];
		}
		sort(s,s+n);
		for(int i=1;i<n;i++)
		{
			s[i]=s[i]*s[i-1]+1;
			sort(s+i,s+n);
		}
		int max=s[n-1];
		sort(t,t+n,cmp);
		for(int i=1;i<n;i++) t[i]=t[i-1]*t[i]+1;
		int min=t[n-1];
		cout<<max-min<<endl;
	}
	return 0;
}
