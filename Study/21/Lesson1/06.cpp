#include<bits/stdc++.h>
using namespace std;
int d,q;
int b[961100];
int ans;
void down(int k)
{
    if(pow(2,(d-1))<=k&&k<pow(2,d))
    {
        ans=k;
        return;
    }
    if(b[k])
    {
        b[k]=!b[k];
        down(2*k+1);
    }
    else
    {
        b[k]=!b[k];
        down(2*k);
    }
}
int main()
{
    cin>>d>>q;
    for(int i=1;i<=q;i++)
        down(1);
    cout<<ans<<endl;
    return 0;
}
