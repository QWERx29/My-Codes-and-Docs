#include<bits/stdc++.h>
using namespace std;
double n,m,sum;
int main ()
{
    cin>>m;
    while(sum<m)
    {
        n++;
        sum+=1/n;
    }
    cout<<n;
    return 0;
}