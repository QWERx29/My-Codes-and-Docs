// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
char s[30];
int main()
{
	scanf("%s",&s);
	int len=strlen(s),k=-1;
	for(int i=0;i<len;i++)
		if(s[i]=='.'||s[i]=='/'||s[i]=='%')
		{
			k=i;break;
		}
	long long a=0,b=0;
	if(k==-1)
	{
		for(int i=len-1;i>=0;i--)
			a=a*10+s[i]-'0';
		cout<<a;
	}
	else
	{
		if(k==len-1)
		{
			for(int i=len-2;i>=0;i--)
				a=a*10+s[i]-'0';
			cout<<a<<s[k];
		}
		else
		{
			for(int i=k-1;i>=0;i--)
				a=a*10+s[i]-'0';
			int start=k+1;
		while(s[start]=='0')start++;
		for(int j=len-1;j>=start;j--)
			b=b*10+s[j]-'0';
		cout<<a<<s[k]<<b;
		}
	}
}
