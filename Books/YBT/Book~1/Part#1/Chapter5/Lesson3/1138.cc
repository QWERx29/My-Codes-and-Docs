#include<bits/stdc++.h>
using namespace std;
char s[256];
int main()
{
    cin.getline(s,256);
    int l=strlen(s);
    for(int i=0;i<l;i++)
        s[i]=toupper(s[i]);
    cout<<s;
    return 0;
}