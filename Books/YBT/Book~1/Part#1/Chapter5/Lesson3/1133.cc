#include<bits/stdc++.h>
using namespace std;
char s[256];
int main()
{
    cin>>s;
    int l=strlen(s);
    char t=s[0];
    for(int i=0;i<l-1;i++) s[i]+=s[i+1];
    s[l-1]+=t;
    cout<<s;
    return 0;
}