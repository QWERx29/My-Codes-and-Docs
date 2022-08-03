#include<bits/stdc++.h>
#define F(i,a,b) for(register int i=a;i<b;i++)
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    if(l<=2) {cout<<s;return 0;}
    if(s[l-1]=='r'&&s[l-2]=='e') 
    {
        F(i,0,l-2) cout<<s[i];
        return 0;
    }
    else if (s[l-1]=='y'&&s[l-2]=='l') 
    {
        F(i,0,l-2) cout<<s[i];
        return 0;
    }
    else if(s[l-1]=='g'&&s[l-2]=='n'&&s[l-3]=='i') 
    {
        F(i,0,l-3) cout<<s[i];
        return 0;
    }
    else cout<<s;
    return 0;
}