#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int main()
{
    cin>>n>>k;
    while(n!=0)
    { 
        if(n%10==3) t++;
        n/=10;
    }
    if(n%19==0&&t==k) cout<<"YES";
    else cout<<"NO";
    return 0;
}