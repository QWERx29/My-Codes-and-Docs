#include<bits/stdc++.h>
using namespace std;
int a[10086],f[10086],maxn,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        f[a[i]]++;
    }
    for(int i=0;i<=maxn;i++) cout<<f[i]<<endl;
    return 0;
}