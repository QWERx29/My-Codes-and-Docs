#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head,*p,*r;
int x,i,q;
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
void getx(node *head,int x)
{
	node *p;
	p=head->next;
	while(p->next!=NULL)
	{
		if(p->data==x) cout<<p->data<<endl;
		p=p->next;
	}
	if(p->data==x) cout<<p->data<<endl;
}
void getxx(node *head,int x)
{
	node *p;
	p=head->next;
	while(p->next!=NULL)
	{
		if(p->data==x) cout<<p->data<<endl;
		p=p->next;
	}
	if(p->data==x) cout<<p->data<<endl;
}
void get(node *head,int i) 
{ 
	node *p;int j; 
	p=head->next; 
	j=1; 
	while((p!=NULL)&&(j<i)) 
	{ 
		p=p->next; 
		j=j+1; 
	} 
	if((p!=NULL)&&(j==i)) cout<<p->data; 
	else cout<<"i not exsit!"<<endl; 
} 
void insert(node *head,int i,int x)
{
	node *p,*s;int j;
	p=head;
	j=0;
	while((p!=NULL)&&(j<i-1))
	{
		p=p->next;
		j=j+1;
	}
	if(p==NULL) 
	{
		cout<<"no this position!";
	}
	else
	{
		s=new node;
		s->data=x;
		s->next=p->next;
		p->next=s;
		pri(head);
	};
}
void deletei(node *head,int i)
{
	node *p,*s;int j;
	p=head;
	j=0;
	while((p->next!=NULL)&&(j<i-1))
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
		s=p->next;
		p->next=p->next->next;
		s->next=p->next;
	    delete(s);
	    pri(head);
	}
}
int len(node *head)
{
	int n=0;
	p=head->next;
	while(p!=NULL)
	{
		n=n+1;
		p=p->next;
	}
	return n;
}
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
		r=p;
		cin>>x;
	}
/*#1
	cin>>i;
	p=head->next;
    get(head,i);
*/
/*#2
	cin>>i>>q;
	p=head->next;
    insert(head,i,q);
*/
/*#3
	cin>>i;
	p=head->next;
    deletei(head,i);
*/
/*#4
p=head->next;
    
	int leng=len(head);
	cout<<leng;
*/	
}
