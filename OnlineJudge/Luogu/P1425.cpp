// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	int e,f;
	cin>>a>>b>>c>>d;
	e=c-a;f=d-b;
	if(f<0)
	{
		e--;
		f+=60;
	}
	cout<<e<<" "<<f;
}
