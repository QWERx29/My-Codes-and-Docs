#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int number[101],i=0,p=1;
char symbol[101],s[256],t[256];
void pop()
{
	switch(symbol[p--])
	{
		case'+':{number[p]+=number[p+1];break;}
		case'-':{number[p]-=number[p+1];break;}
		case'*':{number[p]*=number[p+1];break;}
		case'/':{number[p]/=number[p+1];break;}
		case'^':
		{
			//number[p]=pow(number[p],number[p+1]);
			for(int i=1;i<number[p+1];i++) number[p]*=number[p+1];
			break;
		}
	}
}
bool can()
{
	if((s[i]=='+'||s[i]=='-')&&symbol[p]!='(') return 1;
	if((s[i]=='*'||s[i]=='/'||s[i]=='^')&&(symbol[p]=='*'||symbol[p]=='/'||symbol[p]=='^')) return 1;
	return 0;
}
int main()
{
	scanf("%s",s);
	s[strlen(s)]=')';
	symbol[p]='(';
	while(i<strlen(s))
	{
		while(s[i]=='(')
		{
			symbol[++p]=s[i];
			i++;
		}
		int x=0;
		while(s[i]>='0'&&s[i]<='9') 
			x=x*10+s[i++]-'0';
		number[p]=x;
		do
		{
			if(s[i]==')')
			{
				while(symbol[p]!='(')
				pop(); 
				number[--p]=number[p+1];
			}
			else
			{
				while(can())
				pop(); 
				symbol[++p]=s[i];
			}
			i++;
		}while(i<strlen(s)&&s[i-1]==')');
	}
	printf("%d",number[0]);
	return 0;
}

