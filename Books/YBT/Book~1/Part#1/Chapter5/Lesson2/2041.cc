#include<bits/stdc++.h>
using namespace std;
int a[25][25],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(i==j||i+j-1==n) a[i][j]+=10;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}