#include<bits/stdc++.h>
using namespace std;
int n,t[10086],r[10086],ans,q[10086];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=n-1;i++) cin>>r[i];
    q[1]=t[1];
    for(int i=2;i<=n;i++)
    {
        q[i]=min(q[i-1]+t[i],q[i-2]+r[i-1]);
    }
    cout<<q[n];
}