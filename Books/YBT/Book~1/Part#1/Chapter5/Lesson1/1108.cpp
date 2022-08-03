#include<bits/stdc++.h>
using namespace std;
int a[10086],b[10086],n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) ans+=a[i]*b[i];
    cout<<ans;
    return 0;
}