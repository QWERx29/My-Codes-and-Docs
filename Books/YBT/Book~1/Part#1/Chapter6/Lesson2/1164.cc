#include<bits/stdc++.h>
using namespace std;
int digit(int n,int k)
{
    while(k--!=1) n/=10;
    return n%10;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<digit(n,k);
    return 0;
}