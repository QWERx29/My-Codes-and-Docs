#include<bits/stdc++.h>
using namespace std;
int n;
int f1[410][410],f2[410][410],s[410];
int main()
{
	cin>>n;
	memset(f1,0x7f,sizeof(f1));
	for(int i=1;i<=n;i++) 
	{
		int p;
		cin>>p;
		s[i]=s[i+n]=p;
		f1[i][i]=f1[i+n][i+n]=0;
	}
	for(int i=1;i<=n*2;i++) s[i]+=s[i-1];
	for(int x=2;x<=n;x++)
	{
		for(int i=1;i<=n*2+1-x;i++)
		{
			int j=i+x-1;
			for(int k=i;k<j;k++)
			{
				f1[i][j]=min(f1[i][j],f1[i][k]+f1[k+1][j]+s[j]-s[i-1]);
				f2[i][j]=max(f2[i][j],f2[i][k]+f2[k+1][j]+s[j]-s[i-1]);
			}	
		}
	}
	int maxn=-1,minn=0x7f7f7f7f;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,f1[i][i+n-1]);
		maxn=max(maxn,f2[i][i+n-1]);
	}
	cout<<minn<<endl<<maxn;
	return 0;
}