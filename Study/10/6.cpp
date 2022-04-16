#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int c,m,e,tot,num;
};
int n,b[10005];
bool cmp(stu q,stu w)
{
	if(q.tot>w.tot) return 1;
	else if(q.tot<w.tot) return 0;
	else
    {
		if(q.c>w.c) return 1;
		else if(q.c<w.c) return 0;
		else
		{
			if(q.num>w.num) return 0;
			else return 1;
        }
    }
}
int main()
{
	stu a[305];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].tot=a[i].c+a[i].m+a[i].e;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;i++) cout<<a[i].num<<" "<<a[i].tot<<endl;
}
