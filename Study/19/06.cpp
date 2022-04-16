#include <bits/stdc++.h>
using namespace std;
char st[256],top;
bool f(string s)
{
	top=0; 
	for(int i=0;i<s.length();i++)
	{
		switch(s[i])
		{
			case '{': if(st[top]=='['||st[top]=='('||st[top] =='<') return false;
			case '[': if(st[top]=='('||st[top] =='<') return false;
			case '(': if(st[top] =='<') return false;
			case '<': st[++top]=s[i];break;
			case ')': if(st[top--]!=s[i]-1) return 0;break;
			case '>':			
			case ']':
			case '}': if(st[top--]!=s[i]-2) return 0;break;			
		}
	}
	if(top)  return false; 
	else return  true;	
}
int main()
{	
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;		
		f(s)?cout<<"YES"<<endl:cout<<"NO"<<endl;
	}
	return 0;
}

