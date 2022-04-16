#include<bits/stdc++.h>
using namespace std;
char a1[100086],b1[100086];
int a[100086],b[100086],c[100086],la,lb,lc,x;
int main()
{
	cin>>a1>>b1;
	la=strlen(a1);lb=strlen(b1);
	for(int i=0;i<la;i++)
	{
		a[la-i]=a1[i]-'0';
	}
	for(int i=0;i<lb;i++)
	{
		b[lb-i]=b1[i]-'0';
	}
	lc=1;x=0;
	while(lc<=la||lc<=lb)
	{
		c[lc]=a[lc]+b[lc]+x;
		x=c[lc]/10;
		c[lc]%=10;
		lc++;
	}
	c[lc]=x;
	if(c[lc]==0) lc--;
	for(int i=lc;i>=1;i--) cout<<c[i];
	cout<<endl;
	return 0;
}
