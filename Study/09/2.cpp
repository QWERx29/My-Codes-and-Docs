#include<bits/stdc++.h>
using namespace std;
char a1[100086],b1[100086],n[100086];
int a[100086],b[100086],c[100086],la,lb,lc,x;
int main()
{
	cin>>a1>>b1;
	if(strlen(a1)<strlen(b1)||(strlen(a1)==strlen(b1)&&strcmp(a1,b1)<0))
	{
		strcpy(n,a1);
		strcpy(a1,b1);
		strcmp(b1,n);
		cout<<"-";
	}
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
		if(a[lc]<b[lc])
		{
			a[lc]+=10;
			a[lc+1]--;
		}
		c[lc]=a[lc]-b[lc];
		lc++;
	}
	c[lc]=x;
	while((c[lc]==0)&&(lc>1)) lc--;
	for(int i=lc;i>=1;i--) cout<<c[i];
	cout<<endl;
	return 0;
}
