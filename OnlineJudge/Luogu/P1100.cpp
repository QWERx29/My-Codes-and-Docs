#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n;
	cin>>n;
	cout<<((n&0x0000ffff)<<16|(n&0xffff0000)>>16); 
}

