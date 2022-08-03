#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    int l=s.length();
    s[l]=' ';
    int sum=1;
    for(int i=1;i<=l;i++)
    {
        
        if(s[i-1]==s[i]) sum++;
        else 
        {
            cout<<sum<<s[i-1];
            sum=1;
        }
    }
    return 0;
}