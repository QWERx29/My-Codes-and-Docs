#include<bits/stdc++.h>
using namespace std;
long long n,sum=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    cout<<sum;
    return 0;
}