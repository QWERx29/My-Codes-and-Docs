#include<bits/stdc++.h>
using namespace std;
char s[256];
int t;
int main()
{
    cin.getline(s,256);
    int l=strlen(s);
    for(int i=0;i<l;i++)
        if(s[i]>='0'&&s[i]<='9') t++;
    cout<<t;
    return 0;
}