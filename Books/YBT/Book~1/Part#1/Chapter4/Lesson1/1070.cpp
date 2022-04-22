#include<bits/stdc++.h>
using namespace std;
double n,m;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        m*=1.001;
    }
    printf("%.4lf",m);
    return 0;
}