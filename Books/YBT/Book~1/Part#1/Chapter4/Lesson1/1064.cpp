#include<bits/stdc++.h>
using namespace std;
int n,x,y,z;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        x+=a;y+=b;z+=c;
    }
    cout<<x<<" "<<y<<" "<<z<<" "<<x+y+z;
    return 0;
}