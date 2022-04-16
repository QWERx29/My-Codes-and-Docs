#include<bits/stdc++.h>
using namespace std;
int f[40000];
int main()
{
    int n,w,sum=0;
    cin>>w>>n;
    for (int i=1;i<=n;i++)
        cin>>f[i];
    sort(f+1,f+n+1);
    int i=1;
    for (int j=n;j>=i;j--)
    {
        if (f[i]+f[j]<=w)
        {
            sum++;
            i++;
        }
        else sum++;
    }   
    cout<<sum;
}
