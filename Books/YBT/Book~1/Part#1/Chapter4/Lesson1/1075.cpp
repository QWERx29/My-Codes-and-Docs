#include<bits/stdc++.h>
using namespace std;
int tot,n,sum,p;
int main()
{
    cin>>tot>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a<=tot)  tot-=a;
        else p++;
    }
    cout<<p<<endl;
    return 0;
}