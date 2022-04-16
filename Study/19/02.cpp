#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
char s[256];
int c[101];
int comp(char s[256])
{
   int i=0,top=0,x,y;
   while(s[i]!='@') 
	{
		switch(s[i])
      	{
			case '+': {c[--top]+=c[top+1]; break;}
			case '-': {c[--top]-=c[top+1]; break;}
			case '*': {c[--top]*=c[top+1]; break;}
			case '/': {c[--top]/=c[top+1]; break;}
			default:
			{ 
				x=0; 
				while (s[i]!=' ') 	
					x=x*10+s[i++]-'0'; 
				c[++top]=x;
				break;
			}
      }
      i++;
    }                
    return c[top];
}

int main()
{
	cin.getline(s,256);
	cout<<comp(s);
	return 0;
}

