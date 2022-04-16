#include<bits/stdc++.h>
#include<string>
using namespace std;
int n;
struct stu
{
	string name;
	int c,m,t;
};
stu a[1005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name;
		cin>>a[i].c>>a[i].m;
		a[i].t=a[i].c+a[i].m;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j].t<a[j+1].t) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i].name<<" "<<a[i].c<<" "<<a[i].m<<" "<<a[i].t<<"\n";
	return 0;
}
