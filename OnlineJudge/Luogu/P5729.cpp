#include<bits/stdc++.h>
using namespace std;
int w,x,h,ans,q,a[21][21][21];
int main()
{
    cin>>w>>x>>h>>q;
    while(q--)
    {
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=min(x1,x2);i<=max(x1,x2);i++)
        {
            for(int j=min(y1,y2);j<=max(y1,y2);j++)
            {
                for(int k=min(z1,z2);k<=max(z1,z2);k++)
                {
                    a[i][j][k]=1;
                }
            }
        }
    }
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<=h;k++)
            {
                if(a[i][j][k]==0) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
