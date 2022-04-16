#include<bits/stdc++.h>
using namespace std;
char s1[100086],s2[100086],s3[100086],a[100086];
long long t2,t1,p,js[100086],topjs;
int lev(char n)
{
	if(n=='+'||n=='-') return 1;
	if(n=='*'||n=='/') return 2;
	if(n=='^') return 3;
	return 0;
}
void print()
{
	for(int i=1;i<=topjs;i++) cout<<js[i]<<" ";
	for(int i=p+1;i<=t2;i++)
	{
		cout<<s2[i];
		if(i!=t2) cout<<" ";
	}
	if(p!=t2) cout<<endl;
}
int main()
{
	long long n; 
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9') s2[++t2]=a[i];
		else
		{
			if(a[i]=='(')
			{
				s1[++t1]=a[i];
				continue;
			}
			if(s1[t1]=='('||t1==0)
			{
				s1[++t1]=a[i];
				continue;
			}
			if(lev(s1[t1])>=lev(a[i])&&a[i]!=')')
			{
				s2[++t2]=s1[t1--];
				while(lev(s1[t1])>=lev(a[i]))
				{
					s2[++t2]=s1[t1--];
				}
				s1[++t1]=a[i];
				continue;
			}
			if(lev(s1[t1])<lev(a[i])&&a[i]!=')')
			{
				s1[++t1]=a[i];
				continue;
			}
			if(a[i]==')')
			{
				while(s1[t1]!='(') s2[++t2]=s1[t1--];
				--t1;
				continue;
			}
		}
	}
	while(t1>0) s2[++t2]=s1[t1--];

	for(int i=1;i<=t2;i++) cout<<s2[i]<<" ";
	cout<<endl;
	for(int i=1;i<=t2;i++)
	{	
		p=i;
		if(s2[i]>='0'&&s2[i]<='9') js[++topjs]=s2[i]-'0';
		else
		{
			if(s2[i]=='+')
			{
				long long  y=js[topjs];
				long long  x=js[--topjs];
				long long  ans=x+y;
				js[topjs]=ans;
			}
			if(s2[i]=='-')
			{
				long long  y=js[topjs];
				long long  x=js[--topjs];
				long long  ans=x-y;
				js[topjs]=ans;
			}
			if(s2[i]=='*')
			{
				long long  y=js[topjs];
				long long  x=js[--topjs];
				long long  ans=x*y;
				js[topjs]=ans;
			}
			if(s2[i]=='/')
			{
				long long  y=js[topjs];
				long long  x=js[--topjs];
				long long  ans=x/y;
				js[topjs]=ans;
			}
			if(s2[i]=='^')
			{
				long long  y=js[topjs];
				long long  x=js[--topjs];
				long long  ans=pow(x,y);
				js[topjs]=ans;
			}
			print();
		}
	}
	return 0;
}
