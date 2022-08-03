#include<bits/stdc++.h>
using namespace std;
char s[256];
int main()
{
    cin.getline(s,256);
    int l=strlen(s);
    for(int i=0;i<l;i++) 
    {
        if(isalpha(s[i])) 
        {
            if(s[i]=='Z'||s[i]=='z') s[i]-=25;
            else s[i]++;
        }
    }
    cout<<s;
    return 0;
}