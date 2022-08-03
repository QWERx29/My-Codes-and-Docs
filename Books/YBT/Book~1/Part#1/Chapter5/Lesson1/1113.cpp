#include<bits/stdc++.h>
using namespace std;
int a[10086],n,maxn=-12345,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=maxn) sum+=a[i];
    }
    cout<<sum;
    return 0;
}