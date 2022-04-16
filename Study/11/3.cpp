#include<bits/stdc++.h>
using namespace std;
int fb(int n)
{
	if(n==1||n==2) return 1;
	else return fb(n-1)+fb(n-2);
}
int main()
{
	int m;
	cin>>m;
	cout<<fb(m+1);
	return 0;
}

