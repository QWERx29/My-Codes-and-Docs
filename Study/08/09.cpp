#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;*b=t;
}
void sorta(int *x,int *y,int *z)
{
	if(*x>*y) swap(x,y);
	if(*x>*z) swap(x,z);
	if(*y>*z) swap(y,z);
} 
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	sorta(&a,&b,&c);
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
