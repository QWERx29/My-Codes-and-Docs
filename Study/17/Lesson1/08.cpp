#include<bits/stdc++.h>
using namespace std;
string x,y;
int c[2][1010];
int main()
{
    cin>>x>>y;
    int q=x.length(),w=y.length();
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=w;j++)
        {
            c[i%2][j]=max(c[i%2][j-1],c[(i-1)%2][j]);
            if(x[i-1]==y[j-1]) c[i%2][j]=max(c[i%2][j],c[(i-1)%2][j-1]+1);
        }
    }
    cout<<c[q%2][w];
}