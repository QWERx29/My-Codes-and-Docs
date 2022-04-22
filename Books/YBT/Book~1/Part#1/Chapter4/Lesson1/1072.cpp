#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    double z=1.0*y/x;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        double c=1.0*b/a;
        if(c-z>0.05) cout<<"better\n";
        else if(z-c>0.05) cout<<"worse\n";
        else cout<<"same\n";
    }
    return 0;
}