#include<bits/stdc++.h>
using namespace std;
int main()
{
	void *p;
	int a;
	double b;
	cin>>a>>b;
	p=&a;
	cout<<*(int*)p<<"\n";
	p=&b;
	cout<<*(double*)p;
	return 0;
}
