#include<bits/stdc++.h>
using namespace std;
char c[512];
bool judge(char c[512]) 
{ 
    int top=0,i=0;
    while (c[i]!='@') 
    {
        if (c[i]=='(') top++;
        if (c[i]==')') 
        {
           if (top>0) top--;
             else return 0;
        }
        i++;
    }
    if (top!=0) return 0;         
    else return 1;
}

int main()
{
	scanf("%s",c);
	if(judge(c)) cout<<"YES";
	else cout<<"NO";
	return 0;
}

