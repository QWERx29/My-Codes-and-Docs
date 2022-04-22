#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main()
{
    cin>>m>>n;
    for(int i=m;i<=n;i++)
    {
        if(i%17==0) sum+=i;
    }
    cout<<sum;
    return 0;
}