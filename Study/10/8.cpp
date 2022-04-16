#include<bits/stdc++.h>
using namespace std;
int n,m,o;
struct stu
{
	int id,pt;
};
bool cmp(stu q,stu w)
{
	if(q.pt>w.pt) return 0;
	else if(q.pt<w.pt) return 1;
	else
    {
		if(q.id<w.id) return 0;
		else return 1;
	}
}
int main()
{
	stu a[10086],b[10086];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].id>>a[i].pt;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		b[n+1-i].id=a[i].id;
		b[n+1-i].pt=a[i].pt;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(b[i].pt>=b[int(m*1.5)].pt) o++;
	}
	cout<<b[o].pt<<" "<<o<<endl;
	for(int i=1;i<=o;i++) cout<<b[i].id<<" "<<b[i].pt<<endl;
}
