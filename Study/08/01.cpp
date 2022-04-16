#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,*p,*q,s,t;
	cin>>a>>b;
	p=&a;q=&b;
	s=*p+*q;
	t=*p**q;
	printf("%d %d",s,t);
	return 0;
}
