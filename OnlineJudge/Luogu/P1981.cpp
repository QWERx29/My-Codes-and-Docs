// luogu-judger-enable-o2
#include<bits/stdc++.h> 
using namespace std;
string s;
int n,num[100005],p[100005],ans;
int main()
{
	cin>>s;
	n=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>=48&&s[i]<=57) num[n]=(num[n]*10+s[i]-48)%10000;
		else 
		{
			p[n]=i; 
			n++;
		}
	}
	n++;
	for(int i=1;i<=n;i++)
	{
		if(s[p[i]]=='*')
		{
			num[i+1]=num[i]*num[i+1]%10000; 
			num[i]=0;
		}
	}
	for(int i=1;i<=n;i++) ans=(ans+num[i])%10000;
	cout<<ans;
}
