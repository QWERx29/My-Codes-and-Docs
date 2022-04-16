#include<bits/stdc++.h>
using namespace std;
struct stick
{
	int w,l;
}a[5050];
int n,f[5050],ans;
bool cmp(stick x,stick y)
{
	return x.l>y.l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].w;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].w>f[ans])
		{
			f[ans+1]=a[i].w;
			ans++;
		}
		else
		{
			int q=1,w=ans;
			while(q<w)
			{
				int m=(q+w)/2;
				if(f[m]>=a[i].w) w=m;
				else q=m+1;
			}
			f[q]=a[i].w;
		}
	}
	cout<<ans;
}
