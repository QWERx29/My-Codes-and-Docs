#include<bits/stdc++.h>
using namespace std;
int a[10086],b[10086],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];b[n-i+1]=a[i];}
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}