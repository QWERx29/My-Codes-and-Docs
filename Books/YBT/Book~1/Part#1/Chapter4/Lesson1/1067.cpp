#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,t;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==1) a++;
        else if(t==5) b++;
        else if(t==10) c++;
    }
    cout<<a<<endl<<b<<endl<<c;
    return 0;
}