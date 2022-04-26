#include<bits/stdc++.h>
using namespace std;
double h,n,ans;
int main ()
{
    int i=2;
    cin>>h;
    ans+=h;
    while(i<=10)
    {
        
        
        h*=0.5;ans+=h*2;
        i++;
    }
    cout<<ans<<endl<<h/2;
    return 0;
}