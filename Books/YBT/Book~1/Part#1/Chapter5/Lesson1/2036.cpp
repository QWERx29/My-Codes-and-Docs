#include<bits/stdc++.h>
using namespace std;
int n;
bool a[10086]={true};
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%i==0) a[j]=!a[j];
        }
    }
    for(int i=1;i<=n;i++) 
        if(a[i]==true) cout<<i<<" ";
    return 0;
}