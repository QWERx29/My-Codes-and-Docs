#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t!=0)
        {
            if(t%10==1) ans++;
            t/=10;
        }
    }
    cout<<ans;
    return 0;
}