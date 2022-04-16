// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
long long k,n,ans,s;
int a[10010];
int main()
{
	int i=0;
	cin>>k>>n;
	while(n!=0)
	{
		i++;
		a[i]=n%2;
		n/=2;
    }
    for(int j=i;j>0;j--)
    {
		s=pow(k,j-1);
		ans+=a[j]*s;
    }
    cout<<ans;
}
