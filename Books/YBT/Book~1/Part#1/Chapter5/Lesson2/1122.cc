#include<bits/stdc++.h>
using namespace std;
int maxx[6],miny[6],q,a[6][6],x,y;
int main()
{
    memset(miny,0x7f,sizeof(miny));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++) cin>>a[i][j];
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]>maxx[i]) {maxx[i]=a[i][j];}
            if(a[j][i]<miny[i]) {miny[i]=a[j][i];}
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(maxx[i]==a[i][j]&&miny[j]==a[i][j])
            {
                cout<<i<<" "<<j<<" "<<a[i][j];
                return 0;
            }
        }
    }
    cout<<"not found";
    return 0;
}