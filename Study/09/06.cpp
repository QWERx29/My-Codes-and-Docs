#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,a[10086],b[10086],ans,i;
void init(int a[])
{
	string s;
	cin>>n>>s;
	memset(a,0,sizeof(a));
	a[0]=s.length();
	for(i=1;i<=a[0];i++)
	{
		if(s[a[0]-i]>='0'&&s[a[0]-i]<='9') a[i]=s[a[0]-i]-'0';
		else a[i]=s[a[0]-i]-'A'+10;
	}
}
bool check(int a[])
{
	for(i=1;i<=a[0];i++)
	{
		if(a[i]!=a[a[0]-i+1]) return false;
	}
	return true;
}
void jia(int a[])
{
	for(i=1;i<=a[0];i++) b[i]=a[a[0]-i+1];
	for(i=1;i<=a[0];i++) a[i]+=b[i];
	for(i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/n;
		a[i]%=n;
	}
	if(a[a[0]+1]>0) a[0]++;
}
int main()
{
	init(a);
	if(check(a))
	{
		cout<<0<<endl;
		return 0;
	}
	ans=0;
	while(ans++<=30)
	{
		jia(a);
		if(check(a))
		{
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<"Impossible!"<<endl;
	return 0;
}
