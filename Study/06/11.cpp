#include<bits/stdc++.h>
using namespace std;
long long js(long long a)
{
	if(a==1) return 1;
	else return a*js(a-1);
 } 
int main()
{
	long long c;
	cin>>c;
	cout<<js(c);
	return 0;
}

