#include<bits/stdc++.h>
using namespace std;
int f,v,a[110][110],dp[110][110],ans[110][110];
int main()
{
	cin>>f>>v;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++) cin>>a[i][j];
	for(int i=1;i<=f;i++) dp[i][i]=dp[i-1][i-1]+a[i][i];
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=f;j++)
		{
			dp[i][j]=-1e+8;
			for(int k=0;k<=i-j;k++)
			{
				if(dp[k+j-1][j-1]+a[j][k+j]>dp[i][j])
				{
					ans[i][j]=k+j;
					dp[i][j]=dp[k+j-1][j-1]+a[j][k+j];
				}
			}
		}
	}
	cout<<dp[v][f]<<endl;
	stack<int> st;
    int a=f,b=v;
    for(int i=1;i<=f;i++)
    {
        st.push(ans[b][a]);
        b=ans[b][a]-1;
        a--;
    }
    bool f=1;
    while(!st.empty())
    {
        if(f)
        {
            f=0;
            cout<<st.top();
        }
        else cout<<" "<<st.top();
        st.pop();
    }
	return 0;
}