#include<bits/stdc++.h>
#define N 96110
#define ll long long
double n,p,k; 
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
//	freopen("113.in","r",stdin);
//	freopen("113.out","w",stdout);
	while(cin>>n>>p)
	{
		printf("%.0lf\n",pow(p,1/n));
	}
	return 0;
}

