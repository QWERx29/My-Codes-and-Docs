#include<bits/stdc++.h>
using namespace std;
void h(int n,char a,char b,char c)
{
	if(n==1) cout<<a<<"->"<<c<<endl;
	else
	{
		h(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		h(n-1,b,a,c);
	}
}
int main()
{
	int n;
	cin>>n;
	h(n,'A','B','C');
	return 0;
}
