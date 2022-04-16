// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n=0;
	double sn=0;
	cin>>k;
	while(sn<=k)
	{
		++n;
		sn+=1.0/n;
    }
    cout<<n;
}
