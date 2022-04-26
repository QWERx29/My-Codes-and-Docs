#include<bits/stdc++.h>
using namespace std;
const int INF=123456789;
int n,maxn=-INF,minn=INF,sum,i;
int main ()
{
    while(cin>>n)
    {
        i++;
        sum+=n;
        maxn=max(maxn,n);
        minn=min(minn,n);
    }
    printf("%d %d %.3lf",minn,maxn,1.0*sum/i);
    return 0;
}