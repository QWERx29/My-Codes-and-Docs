#include<bits/stdc++.h>
using namespace std;
char s[256];
bool f;
int main()
{
    cin>>s;
    int l=strlen(s);
    for(int i=0;i<l;i++) 
    {
        if(isalnum(s[i])||s[i]=='_') continue;
        else {cout<<"no";return 0;}
    }
    if(s[0]<='9'&&s[0]>='0') cout<<"no";
    else cout<<"yes";
    return 0;
}