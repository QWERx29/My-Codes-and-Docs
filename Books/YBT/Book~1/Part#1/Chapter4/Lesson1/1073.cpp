#include<bits/stdc++.h>
using namespace std;
double n,x,y,p,d,t;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>p;
        d=sqrt(x*x+y*y);
        t+=d*2/50+1.5*p;
    }
    cout<<(int)ceil(t)<<endl;
}