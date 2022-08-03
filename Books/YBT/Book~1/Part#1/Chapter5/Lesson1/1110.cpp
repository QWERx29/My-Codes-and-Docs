#include<bits/stdc++.h>
using namespace std;
int a[10086],n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==m) 
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}