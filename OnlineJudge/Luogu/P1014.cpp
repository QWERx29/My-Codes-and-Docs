#include<bits/stdc++.h>
using namespace std;
int n,i,j;
int main()
{
	cin>>n;
	while(j<n)
	{
		i++;
		j+=i;
	}
	if(i%2==1) cout<<j-n+1<<"/"<<i+n-j;
	else cout<<i+n-j<<"/"<<j-n+1;
}
