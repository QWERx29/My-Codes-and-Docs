#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
stack<int>digit;
stack<char>sym;
int level(char c) 
{
	if(c=='+'||c=='-') return 1;
	if(c=='*'||c=='/') return 2;	
	if(c=='^') return 3;
	return 0;
}
void calc() 
{
	int a=digit.top();
	digit.pop();
	int b=digit.top();
	digit.pop();
	char ch=sym.top();
	sym.pop();
	if(ch=='+') digit.push(a+b);
	else if(ch=='-') digit.push(b-a);
	else if(ch=='*') digit.push(a*b);
	else if(ch=='/') digit.push(b/a);
	else if(ch=='^') digit.push(pow(b, a));
}
int main()
{
	string str;
	cin>>str;
	int len=str.length();
	int x=0;
	bool tag=false;
	for(int i=0;i<len;i++) 
	{
		if(str[i]>='0'&&str[i]<='9') 
		{
			x=x*10+str[i]-'0';
			tag=true;
		}
		else 
		{
			if(tag) 
			{
				digit.push(x);
				tag=false;
				x=0;
			}
			if(str[i]=='(') 
			{
				sym.push(str[i]);
				continue;
			}
			if(str[i]==')') 
			{
				while(sym.top()!='(') calc();
				sym.pop();
				continue;
			}
			while(!sym.empty() && level(sym.top())>= level(str[i])) calc();
			sym.push(str[i]);
		}
	}
	if(tag) digit.push(x);
	while(!sym.empty()) calc();
	cout<<digit.top()<<endl;
	return 0;
}
