#include<bits/stdc++.h>
using namespace std;
string s1,s2;
double t,s;
int main()
{
    cin>>s>>s1>>s2;
    int l=s1.length();
    for(int i=0;i<l;i++)
        if(s1[i]==s2[i]) t++;
    if(t/l>s) cout<<"yes";
    else cout<<"no";
    return 0;
}