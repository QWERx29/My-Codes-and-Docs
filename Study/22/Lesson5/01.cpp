#include<bits/stdc++.h>
const int N=110;
int a[N][N],c[N],r[N],ans[N];
int tot,tmp,num,n,m;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	do
    	{
    		cin>>m;
    		if(m!=0)
    		{
    			c[i]++;
    			a[i][c[i]]=m;
    			r[m]++;
			}
		}while(m!=0);
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]==0)  ans[++tot]=i;
	}
	do
	{
		tmp=ans[tot];
		cout<<tmp<<" ";
		tot--;num++;
		for(int i=1;i<=c[tmp];i++)
		{
			r[a[tmp][i]]--;
			if(r[a[tmp][i]]==0) ans[++tot]=a[tmp][i];
		}
	}while(num!=n);
	return 0;
}

