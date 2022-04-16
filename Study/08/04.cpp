#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,*p,**pp;
	
	cin>>a;
	p=&a;pp=&p;
	cout<<a<<"\n"<<*p<<"\n"<<**pp;
	return 0;
}
