#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double e=1;
int main()
{
    cin>>n;
    ll m=1;
    for(int i=1;i<=n;i++)
    {
        m*=i;
        e+=1.0/m;
    }
    printf("%.10f",e);
}