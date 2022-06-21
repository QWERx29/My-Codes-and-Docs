#include<bits/stdc++.h> 
using namespace std;
const int N=10086;
struct Node{int l,r;}a[N];
int pro[N],ans[N],tmp[N],n;
bool cmp(Node q,Node w){return q.l*q.r<w.l*w.r;}
void copy(int *aa,int *bb){for(int i=0;i<N;i++) aa[i]=bb[i];}
bool more(int *aa,int *bb)
{
	for(int i=N-1;i>=0;i--)
	{
		if(aa[i]>bb[i]) return 1;
		if(aa[i]<bb[i]) return 0;
	}
	return 0;
}
void mul(int *aa,int num)
{
	for(int i=N-2;i>=0;i--) aa[i]*=num;
	for(int i=0;i<N-1;i++)
	{
		aa[i+1]+=(aa[i]/10);
		aa[i]%=10;
	}
}
void div(int *aa,int *bb,int num)
{
	memset(bb,0,sizeof(bb));
	int x=0;
	for(int i=N-1;i>=0;i--)
	{		
    	x=x*10+aa[i];	
		bb[i]=x/num;	
		x%=num;	
	}
}
void print(int *aa)
{
	bool flag=0;
	for(int i=N-1;i>=0;i--)
	{
		if(!flag)
		{
			if(aa[i]) flag=1;
			else continue;
		}
		cout<<aa[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=n;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+n+1,cmp);
	pro[0]=1;
	for(int i=0;i<=n;i++)
	{
		div(pro,tmp,a[i].r);
		if(more(tmp,ans)) copy(ans,tmp);
		mul(pro,a[i].l);
	}
	print(ans);
	return 0;
}