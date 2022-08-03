#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()>s2.length()) 
    {
        if(s1.find(s2,0)!=string::npos) cout<<s2<<" is substring of "<<s1;
        else cout<<"No substring";
    }
    else
    {
        if(s2.find(s1,0)!=string::npos) cout<<s1<<" is substring of "<<s2;
        else cout<<"No substring";
    }
    return 0;
}