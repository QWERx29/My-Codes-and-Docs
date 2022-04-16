#include<iostream> 
using namespace std; 
struct Node 
{ 
  int data; 
  Node *next; 
}; 
Node *head,*p,*r; //r指向链表的当前最后一个结点，可以称为尾指针
int x,lenght,i; 
void pri(Node *head) 
{ Node *p; 
p=head->next; //头指针没有数据，只要从第一个结点开始就可以了} 
while(p->next!=NULL) 
{ 
cout<<p->data<<" "; 
p=p->next; 
} 
cout<<p->data<<endl; //最后一个结点的数据单独输出，也可以改用do-while循环} 
} 

void getx(Node *head,int x) 
{ Node *p; 
p=head->next; 
while((p->data!=x)&&(p->next!=NULL))p=p->next; //找到第一个就结束 
if(p->data==x)cout<<p->data<<endl; 
else cout<<x<<" not exsit!"<<endl;  
}
void getxx(Node *head,int x) 
{ Node *p; 
  p=head->next; 
  while(p->next!=NULL) //一个一个判断 
  { 
    if(p->data==x)cout<<p->data<<endl;  
    p=p->next; 
   } 
}

void get(Node *head,int i) 
{ Node *p;int j; 
p=head->next; 
j=1; 
while((p!=NULL)&&(j<i)) 
{ 
p=p->next; 
j=j+1; 
} 
if((p!=NULL)&&(j==i))cout<<p->data; 
else cout<<"i not exsit!"<<endl; 
} 
void insert(Node *head,int i,int x)//插入X到第i个元素之前
{ Node *p,*s;int j; 
p=head; 
j=0; 
while((p!=NULL)&&(j<i-1))//寻找第i-1个结点,插在它的后面 
{ 
p=p->next; 
j=j+1; 
} 
if(p==NULL)cout<<"no this position!"; 
else{ //插入 
s=new Node; 
s->data=x; 
s->next=p->next; 
p->next=s; 
/*p=head->next; //头指针没有数据，只要从第一个结点开始就可以了} 
while(p->next!=NULL) 
{ 
  cout<<p->data<<" "; 
  p=p->next; 
} 
cout<<p->data<<endl; //最后一个结点的数据单独输出，也可以改用dowhile循环}
*/
}
} 
void deletei(Node *head,int i) //删除第i个元素 
{ 
Node *p,*s;int j; 
p=head; 
j=0; 
while((p->next!=NULL)&&(j<i-1)) 
{ 
p=p->next; 
j=j+1; 
} //p指向第i-1个结点 
if (p->next==NULL) 
cout<<"no this position!"; 
else 
{ //删除p的后继结点，假设为s 
s=p->next; 
//p->next=p->next->next; 
p->next=s->next; 
p=head->next; //头指针没有数据，只要从第一个结点开始就可以了} 
while(p->next!=NULL) 
{ 
  cout<<p->data<<" "; 
  p=p->next; 
} 
cout<<p->data<<endl;
} 
} 
int len(Node *head) 
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
 head=new Node; //申请头结点 
 r=head; 
 while(x!=-1) //读入的数非-1 
 { 
  p=new Node; //则，申请一个新结点 
  p->data=x; 
  p->next=NULL; 
  r->next=p; //把新结点链接到前面的链表中，实际上r是p的直接前趋 
  r=p; //尾指针后移一个 
  cin>>x; 
 } 

//get(head,4); 
//pri(head);
//getx(head,5); 
//pri(head);
//getxx(head,5); 
//pri(head);
cin>>i>>x;
insert(head,i,x);
pri(head);
cin>>i;
deletei(head,i);
pri(head);
/*
lenght=len(head);

cout<<endl;
cout<<lenght<<endl;*/
} 


