#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next,*pre;
};
node *head,*p,*r;
void pri(node *head)
{
	node *p;
	p=head->next;
	while(p->next!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
}
void insert(node *head,int i,int x)
{
	node *s,*p;
	int j;
	s=new node;
	s->data=x;
	p=head;
	j=0;
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;
		j=j+1;
	}
	if(p->next==NULL)
	{
		cout<<"no this position!";
	}
	else 
	{
		s->pre=p->pre;
		p->pre->next=s;
		s->next=p;
		p->pre=s;
		pri(head);
	}
}
void deletei(node *head,int i)
{
	int j;
	node *p;
	p=head;
	j=0;
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;
		j=j+1;
	}
	if(p->next==NULL)
	{
		cout<<"no this position!";
	}
	else 
	{
		p->pre->next=p->next;
		p->next->pre=p->pre;
		pri(head);
	}
}
int i,x,t;
int main()
{
	cin>>x;
	head=new node;
	r=head;
	while(x!=-1)
	{
		p=new node;
		p->data=x;
		p->next=NULL;
		r->next=p;
		p->pre=r;
		r=p;
		cin>>x;
	}
	p=head->next;
	cin>>i;
	deletei(head,i);
	return 0;
}
