#include<bits/stdc++.h>
using namespace std;
const int N=961100;
int n,c,a[N];
bool solve(int mid)
{
    int pre=1,cnt=1;
    for(int i=2;i<=n;i++)
    if(a[i]-a[pre]>=mid)cnt++,pre=i;
    return cnt>=c;
}
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-a-1;
    int l=1,r=1e9+10;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(solve(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
