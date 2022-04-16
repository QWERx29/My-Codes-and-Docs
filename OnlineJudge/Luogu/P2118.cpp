#include<bits/stdc++.h>
using namespace std;
int a,b,l,ans1,ans2=1,a1=1,b1=1;
int main()
{
	cin>>a>>b>>l;
	ans1=l;
	while(a1<=l&&b1<=l)
	{
		if(a*b1<=b*a1)
		{
			if(a1*ans2<b1*ans1)
			{
				ans1=a1;
				ans2=b1;
			}
			b1++;
		}
		else a1++;
	}
	cout<<ans1<<" "<<ans2;
}
