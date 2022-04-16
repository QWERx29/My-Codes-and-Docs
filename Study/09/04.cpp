#include<bits/stdc++.h>
using namespace std;
char a1[100086];
int a[100086],b,c[100086],la,lc,x;
int main()
{
	cin>>a1;cin>>b;
	la=strlen(a1);
	for(int i=0;i<la;i++)	a[i+1]=a1[i]-'0';
	for(int i=1;i<=la;i++)
	{
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lc=1;
	while(c[lc]==0&&lc<la) lc++;
	for(int i=lc;i<=la;i++) cout<<c[i];
	return 0;
}
