#include<bits/stdc++.h>
using namespace std;
const int N=84759359;
long long q[N];
int a,n;
void work(int a,int n)
{
	int r=2;
	q[1]=a;
	int q2=1,q3=1;
	while(r<=n)
	{
		long long t1=q[q2]*2+1,t2=q[q3]*3+1;
		int t=min(t1,t2);
		if(t1<t2) q2++;
		else q3++;
		if(t==q[r-1]) continue;
		q[r++]=t;
	}
	cout<<q[n]<<endl;
}
int main()
{
	while(cin>>a>>n)
	 	work(a,n);
	return 0;
}

