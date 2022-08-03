#include<bits/stdc++.h>
using namespace std;
char s[256];
bool f[256]={true};
int main()
{
    cin.getline(s,256);
    int l=strlen(s);
    for(int i=0;i<l;i++) 
    {
        if((s[i]<='Z'&&s[i]>='X')||(s[i]<='z'&&s[i]>='x')) s[i]-=23;
        else s[i]+=3;
        if(isupper(s[i])) s[i]=tolower(s[i]);
        else s[i]=toupper(s[i]);
    }
    for(int i=l-1;i>=0;i--) cout<<s[i];
    return 0;
}