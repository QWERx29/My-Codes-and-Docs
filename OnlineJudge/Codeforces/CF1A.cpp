#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
    int a,m,n;
    int i;
    cin>>n>>m>>a;
    cout<<(long long)ceil(n/(double)a)*ceil(m/(double)a);
	return 0;
}

