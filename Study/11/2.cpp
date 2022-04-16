#include<bits/stdc++.h>
using namespace std;
int fb(int n)
{
	if(n==1) return 0;
	if(n==2||n==3) return 1;
	else return fb(n-1)+fb(n-2);
}
int main()
{
	int m;
	cin>>m;
	cout<<fb(m);
	return 0;
}

