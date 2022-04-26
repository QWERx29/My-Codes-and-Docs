#include<bits/stdc++.h>
using namespace std;
int m,n,q;
char ch;
int main()
{
    cin>>m>>n>>ch>>q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(q==0)
            {
                if(i==1||i==m) cout<<ch;
                else
                {
                    if(j==1||j==n) cout<<ch;
                    else cout<<" ";
                }
                
            }
            else cout<<ch;
        }
        cout<<endl;
    }
    return 0;
}