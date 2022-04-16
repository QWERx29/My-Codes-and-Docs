#include<iostream>
#include<algorithm>
#define gc getchar
using namespace std;
inline int rd() 
{
	int x=0,f=1;
	char c=gc();
	while (c<'0'||c>'9') 
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(c>='0'&&c<='9') 
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=gc();
	}
	return x*f;
}
long long max(long long a,long long b)
{
	return a>b?a:b; 
} 
long long n,m,k;
long long d[9611000],num[9611000],last[9611000],time1[9611000],date[9611000];
long long ans=0;
int main()
{
	n=rd();m=rd();k=rd();
	for(long long i=2;i<=n;i++)
		d[i]=rd();
	for(long long i=1;i<=m;i++)
	{
		long long a,b,c;
		a=rd();b=rd();c=rd();
		ans-=a;
		num[c]++;
		last[b]=max(a,last[b]);
	}
	for(long long i=2;i<=n;i++)
		time1[i]=max(time1[i-1],last[i-1])+d[i];
	long long bz=0;
	for(long long i=1;i<=k;i++)
	{
		for(long long j=n;j>=2;j--)
		{
			date[j]=num[j]; 
			if(last[j]<time1[j])date[j]+=date[j+1];
		}
		long long maxn=0;
		for(long long j=2;j<=n;j++)
		{
			if(date[j]>maxn&&d[j]>0)
			{
				maxn=date[j];
				bz=j;
			}
		}
		d[bz]--;
		for(long long j=bz;j<=n;j++) time1[j]=max(time1[j-1],last[j-1])+d[j];
	} 
	for(long long i=2;i<=n;i++) ans+=num[i]*time1[i];
	cout<<ans;
	return 0; 
}
