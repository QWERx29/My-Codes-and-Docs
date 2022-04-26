#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool flag;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t=i;
        flag=true;
        while(t!=0)
        {
            if(t%10==7) flag=false;
            t/=10;
        }
        if(i%7==0) flag=false;
        if(flag==true) ans+=i*i;
    }
    cout<<ans;
    return 0;
}