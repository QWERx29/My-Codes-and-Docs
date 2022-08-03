#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[10086];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=n;i++)
        if(a[i]==m) t++;
    cout<<t;
    return 0;
}