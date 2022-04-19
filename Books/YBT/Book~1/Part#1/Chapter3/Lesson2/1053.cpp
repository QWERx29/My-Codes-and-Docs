#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,maxx=-123456789;
    cin>>a>>b>>c;
    if(a>maxx) maxx=a;
    if(b>maxx) maxx=b;
    if(c>maxx) maxx=c;
    cout<<maxx;
    return 0;
}