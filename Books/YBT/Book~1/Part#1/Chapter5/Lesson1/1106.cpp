#include<bits/stdc++.h>
using namespace std;
int p[10086],a,b,c,d,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        if(p[i]>=0&&p[i]<=18) a++;
        if(p[i]>=19&&p[i]<=35) b++;
        if(p[i]>=36&&p[i]<=60) c++;
        if(p[i]>=61) d++;
    }
    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%\n",a*100.0/n,b*100.0/n,c*100.0/n,d*100.0/n);
}