#include<iostream>
#include<cstdio>
struct node 
{
	char data;
	node* lchild;
	node* rchild;
};
void create(node* &root) 
{
	char c;
	scanf("%c",&c);
	if (c=='.') root=NULL;
	else 
	{
		root=new node;
		root->data=c;
		create(root->lchild);
		create(root->rchild);
	}
	
}
void inorder(node* root) 
{
	if (root==NULL) return;
	inorder(root->lchild);
	printf("%c",root->data);
	inorder(root->rchild);
}
void porder(node* root) 
{
	if (root==NULL) return;
	porder(root->lchild);
	porder(root->rchild);
	printf("%c",root->data);
}
int main() 
{
	node* btnode=new node;
	create(btnode);
	inorder(btnode);
	printf("\n");
	porder(btnode);
	return 0;
}
