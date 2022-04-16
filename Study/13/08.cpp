#include<bits/stdc++.h>
using namespace std;
int n,a[100],b[100];
void dfs(int k)
{
    int i;
    if(k==n) 
    {
    	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    	cout<<endl;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!a[i])
        {
            a[i]=1;
            b[k+1]=i;
            dfs(k+1);
            a[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
