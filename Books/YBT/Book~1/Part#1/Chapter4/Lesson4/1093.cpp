#include<bits/stdc++.h>
using namespace std;
int n;
double ans=1,x,m=1;
int main()
{
    cin>>x>>n;
    for(int i=1;i<=n;i++)
    {
        m*=x;
        ans+=m;
    }
    printf("%.2lf",ans);
    return 0;
}