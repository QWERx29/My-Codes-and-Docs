#include<bits/stdc++.h>
using namespace std;
const int N=1145141*2;
const int M=1e6;

int L,R,ans;
bool p[N];

int main()
{
	cin>>L>>R;
	memset(p,1,sizeof(p));
	for(int i=2;i<=sqrt(R);i++)
	{
		for(int j=max(2,L/i);j<=(R/i);j++)
			p[i*j-L+M]=false;
	}
	for(int i=0;i<=R-L;i++) 
		if(p[i+M]) ans++;
	if(L==1) ans--;
	cout<<ans;
	return 0;
}