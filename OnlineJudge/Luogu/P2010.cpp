// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int d1,d2,ans,sum,q;
int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	cin>>d1>>d2;
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=s[i];j++)
		{
			q=(j%10)*1000+(j/10)*100+(i%10)*10+i/10;
			sum=q*10000+i*100+j;
			if(sum<d1||sum>d2) continue;
			ans++;
		}
    }
    cout<<ans;
}
