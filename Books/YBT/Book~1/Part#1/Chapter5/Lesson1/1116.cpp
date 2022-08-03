#include<bits/stdc++.h>
using namespace std; 
int n,a[100001],m=-9999,len=1;
int main() 
{
    cin>>n;
    a[0]=-3456497;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]) len++;
        else len=1;
        if(len>m) m=len;
    }
    cout<<m;
    return 0;
}