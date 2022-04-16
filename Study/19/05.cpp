#include<bits/stdc++.h>
using namespace std;
char s[10086],c[10086];
int top;
int main()
{
	cin.getline(s,10086);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]=='('||s[i]=='[')
        {
            c[top]=s[i];
            top++;
        }
        else if(s[i]==')')
        {
            if(c[top-1]=='(') top--;
            else 
            {
                cout<<"Wrong";
                return 0;
            }
        }
        else if(s[i]==']')
        {
            if(c[top-1]=='[') top--;
            else 
            {
                cout<<"Wrong";
                return 0;
            }
         }   
    }
    if(top==1) cout<<"Wrong";
	else cout<<"OK";
	return 0;
}
