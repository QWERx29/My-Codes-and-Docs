#include <bits/stdc++.h>
using namespace std;
bool a[5005];
int n,m; 
int main()
{
    
    cin>>n>>m;
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            if(j%i==0) a[j]=!a[j];
    }
    bool isFirst=true;
    for(int j=1;j<=n;j++)
    {
        if(a[j]==false)
        {
            if(isFirst) isFirst=false;
            else cout<< ',';
            cout<<j;
        }
    }
    return 0;
}
