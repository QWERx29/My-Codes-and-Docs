#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[i]==s[l-i-1]) continue;
        else 
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}