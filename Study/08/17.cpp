#include<bits/stdc++.h>
using namespace std;
struct node
{
	long d;
	node *next;
};
long n,m;
node *head,*p,*r;
int main()
{
	long i,j,k,l;
	cin>>n>>m;
	head=new node;
	head->d=1;head->next=NULL;r=head;
	for(i=2;i<=n;i++)
	{
		p=new node;
		p->d=i;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	r->next=head;r=head;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m-2;j++)
			r=r->next;
		cout<<r->next->d<<" ";
		r->next=r->next->next;
		r=r->next;
	}
	return 0;
}

