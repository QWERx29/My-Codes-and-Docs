#include<bits/stdc++.h>
#include<string>
using namespace std;
int n;
struct node
{
	int data,rank,index;
};
node a[10005];
bool cmp1(node x,node y)
{
	return x.data<y.data;
}
bool cmp2(node x,node y)
{
	return x.index<y.index;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].data;
		a[i].index=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) a[i].rank=i;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		cout<<a[i].rank<<" ";
	return 0;
}
