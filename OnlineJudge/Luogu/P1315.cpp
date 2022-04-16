#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int d[961100],num[961100],last[961100],time1[961100],date[961100];
int  ans=0;
int main()
{
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) cin>>d[i];
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ans-=a;
		num[c]++;
		last[b]=max(a,last[b]);
	}
	for(int i=2;i<=n;i++)
		time1[i]=max(time1[i-1],last[i-1])+d[i];
	int bz=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=n;j>=2;j--)
		{
			date[j]=num[j]; 
			if(last[j]<time1[j])date[j]+=date[j+1];
		}
		int maxn=0;
		for(int j=2;j<=n;j++)
		{
			if(date[j]>maxn&&d[j]>0)
			{
				maxn=date[j];
				bz=j;
			}
		}
		d[bz]--;
		for(int j=bz;j<=n;j++) time1[j]=max(time1[j-1],last[j-1])+d[j];
	} 
	for(int i=2;i<=n;i++) ans+=num[i]*time1[i];
	cout<<ans;
	return 0; 
}
