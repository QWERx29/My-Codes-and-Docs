#include<bits/stdc++.h>
using namespace std;
int n;
double sum;
bool f=true;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(f==1) sum+=1.0/i;
        else sum-=1.0/i;
        f=!f;
    }
    printf("%.4lf",sum);
    return 0;
}