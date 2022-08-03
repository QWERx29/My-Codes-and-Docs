#include<bits/stdc++.h>
using namespace std;
double x;
double f(int n)
{
    if(n==1) return sqrt(x+1);
    else return sqrt(n+f(n-1));
}
int main()
{
    int n;
    cin>>x>>n;
    printf("%.2lf",f(n));
    return 0;
}