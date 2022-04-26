#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	cin>>a;
	while(a!=0)
	{
		b=b*10+a%10;
		a/=10;
    }
    cout<<b;
}