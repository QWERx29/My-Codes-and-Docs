#include<bits/stdc++.h>
using namespace std;
int T,n,cnt;
int a[205],w[205],f[40005];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(w,0,sizeof(w));
		cnt=0;
		f[0]=1;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]==0) 
			{
				cnt++;
				for(int j=a[i];j<=a[n];j++) f[j]=f[j-a[i]]|f[j];
			}
		}
	cout<<cnt<<endl;
	}
	return 0;
}