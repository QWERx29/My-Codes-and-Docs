#include<bits/stdc++.h>
using namespace std;
int n,m,w[10001],s[101],maxx;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        maxx=1;
        for (int j=2;j<=m;j++)
        {
        	if (s[maxx]>s[j])  maxx=j;
		}
        s[maxx]+=w[i];
    }
    maxx=1;
    for (int i=1;i<=m;i++) maxx=max(maxx,s[i]);
    cout<<maxx;

}
