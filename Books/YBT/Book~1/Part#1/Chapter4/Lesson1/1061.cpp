#include<bits/stdc++.h>
using namespace std;
int n,sum,a;
double ave;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum+=a;
    }
    ave=sum*1.0/n;
    printf("%d %.5lf",sum,ave);
    return 0;
}