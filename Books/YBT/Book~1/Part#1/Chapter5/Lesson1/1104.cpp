#include<bits/stdc++.h>
using namespace std;
int a[15];
float p[15]={28.9,32.7,45.6,78.0,35,86.2,27.8,43.0,56.0,65.0},sum;
int main()
{
    for(int i=0;i<10;i++) cin>>a[i];
    for(int i=0;i<10;i++) sum+=a[i]*p[i];
    printf("%.1lf",sum);
    return 0;
}