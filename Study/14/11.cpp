#include<bits/stdc++.h>
using namespace std;
int mo[501][501],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
	{
        for(int j=i+1;j<=n;j++) 
		{
            cin>>mo[i][j];
            mo[j][i]=mo[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sort(mo[i],mo[i]+n+1);
        if(mo[i][n-1]>ans) 
            ans=mo[i][n-1];
    }
    cout<<1<<endl<<ans;
    return 0;
}
