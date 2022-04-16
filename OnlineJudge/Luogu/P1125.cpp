#include<bits/stdc++.h>
using namespace std;
char s[200000];
int a[205];
bool b[205];
bool zs(int x)
{
	if(x==0||x==1) return false;
	if(x==2) return true;
	for(int q=2;q*q<=x;q++)
	{
		if(x%q==0) return false;
	}
	return true;
} 
int main()
{
	int maxn=0,minn=999;
	memset(b,true,sizeof(b));
	cin>>s;
	for(int i=0;i<=strlen(s);i++)
	{
		a[s[i]-'a']++;
		b[s[i]-'a']=false;
    }
	for(int i=0;i<26;i++)
	{
		if(a[i]>maxn&&b[i]==false) maxn=a[i];
		if(a[i]<minn&&b[i]==false) minn=a[i];
	}
	if(zs(maxn-minn)==false) cout<<"No Answer"<<endl<<"0";
	else cout<<"Lucky Word"<<endl<<maxn-minn;
}
