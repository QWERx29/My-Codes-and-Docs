#include<bits/stdc++.h>
using namespace std;
typedef struct node;
typedef node *tree;
struct node
{
    char data;
    tree lchild,rchild;
};
tree bt;
int i;
string s;
void crt(tree &bt)
{
	char ch;
	ch=getchar();
	if(ch!='$')
	{
		bt=new node;
		bt->data=ch;
		crt(bt->lchild);
		crt(bt->rchild);
	}
	else bt=NULL;
}
void pre(tree bt)
{
	if(bt)
	{
		cout<<bt->data;
		pre(bt->lchild);
		pre(bt->rchild);
	}
}
void in(tree bt)
{
	if(bt)
	{
		in(bt->lchild);
		cout<<bt->data;
		in(bt->rchild);
	}
}
void post(tree bt)
{
	if(bt)
	{
		post(bt->lchild);
		post(bt->rchild);
		cout<<bt->data;
	}
}
void print(tree bt)
{
	if(bt)
	{
		cout<<bt->data;
		if(bt->lchild||bt->rchild)
		{
			cout<<'(';
			print(bt->lchild);
			if(bt->rchild) cout<<',';
			print(bt->rchild);
			cout<<')';
		}
	}
}
int main()
{
    crt(bt);
    print(bt);
    cout<<endl;
    pre(bt);
    cout<<endl;
    in(bt);
    cout<<endl;
    post(bt);
    cout<<endl;
    return 0;
}
