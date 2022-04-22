#include<bits/stdc++.h>
using namespace std;
int n;
double sum,p=1,q=2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum+=q/p;
        q=q+p;
        p=q-p;
    }
    printf("%.4lf",sum);
    return 0;
}