#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int id,f,s;
  	
}cow;
cow po[50000];
bool cmp1(cow a,cow b)
{
	return a.f<b.f;
}
bool cmp2(cow a,cow b)
{
	return a.s<b.s;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		po[i].id=i+1;
		cin>>po[i].f>>po[i].s;
	}
	sort(po,po+n,cmp1);
	sort(po+n-m,po+n,cmp2);
	cout<<po[n-1].id;
	return 0;
}
