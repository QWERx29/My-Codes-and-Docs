#include<bits/stdc++.h>
using namespace std;
void f(int n)
{    
	if(n==0) return;
    else 
	{ 
		cout<<n%10;
		n/=10;
        f(n);
    }
}
int main()
{
	int n;
	cin>>n;
	f(n);
	return 0;
}

