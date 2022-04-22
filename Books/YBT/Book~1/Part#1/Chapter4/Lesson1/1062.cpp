#include<bits/stdc++.h>
using namespace std;
int n,a,maxx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        maxx=max(a,maxx);
    }
    cout<<maxx;
    return 0;
}