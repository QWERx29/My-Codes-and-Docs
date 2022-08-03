#include<bits/stdc++.h>
#include<string>
using namespace std;
char s[256];
char a,b;
int main()
{
    cin.getline(s,256);
    int l=strlen(s);
    cin>>a>>b;
    for(int i=0;i<l;i++)
        if(s[i]==a) s[i]=b;
    for(int i=0;i<l;i++) cout<<s[i];
    return 0;
}