#include<bits/stdc++.h>
using namespace std;
int a[10086],n,maxn=-12345,minn=12345;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    cout<<maxn-minn;
    return 0;
}