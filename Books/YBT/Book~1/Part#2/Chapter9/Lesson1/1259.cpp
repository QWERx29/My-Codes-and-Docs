#include<bits/stdc++.h>
using namespace std;
int n=1,b[1001],f[1001],ans=1;
int main()
{
	while(cin>>b[n]) f[n]=1,++n;
	n--;
	for(int i=2;i<=n;++i)
	{
        for(int j=1;j<i;++j)
        {
            if(b[i]>b[j])  f[i]=max(f[i],f[j]+1);
        }
		ans=max(f[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
