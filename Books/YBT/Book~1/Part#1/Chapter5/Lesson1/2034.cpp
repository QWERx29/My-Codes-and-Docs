#include<bits/stdc++.h>
using namespace std;
int a[10086],n=1,x;
int main()
{
    while(scanf("%d",&x)==1) a[n++]=x;
    for(int i=n-1;i>=1;i--) cout<<a[i]<<" ";
    return 0;
}