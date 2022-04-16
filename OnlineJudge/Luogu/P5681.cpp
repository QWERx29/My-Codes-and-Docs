#include<bits/stdc++.h>
using namespace std;
long long a,b,c,s1,s2;
int main()
{
    cin>>a>>b>>c;
    s1=a*a;
    s2=b*c;
    if(s1>s2) cout<<"Alice";
    else cout<<"Bob";
    return 0;
} 
