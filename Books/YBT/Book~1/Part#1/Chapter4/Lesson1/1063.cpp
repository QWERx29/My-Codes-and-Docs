#include<bits/stdc++.h>
using namespace std;
int n,a,maxx=-123456789,minn=123456789;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        maxx=max(a,maxx);
        minn=min(minn,a);
    }
    cout<<maxx-minn;
    return 0;
}