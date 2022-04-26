#include<bits/stdc++.h>
using namespace std;
int l,r,ans;
int main()
{
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        int t=i;
        while(t!=0)
        {
            if(t%10==2) ans++;
            t/=10;
        }
    }
    cout<<ans;
    return 0;
}