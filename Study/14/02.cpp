#include<bits/stdc++.h>
using namespace std;
int n,ave,ans;
int a[10086];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ave+=a[i];
	}
	ave/=n;
	for(int i=1;i<=n;++i) a[i]-=ave;
	int q=1,w=n;
	while(a[q]==0&&q<n) ++q;
	while(a[w]==0&&w>1) --w;
	while(q<w)
	{
		a[q+1]+=a[q]; 
		a[q]=0;
		++ans;
		++q;
		while(a[q]==0&&q<w) ++q;
  } 
  cout<<ans<<endl;
  return 0;
}

