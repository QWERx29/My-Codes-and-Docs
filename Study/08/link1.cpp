#include<iostream> 
using namespace std; 
struct Node 
{ 
int data; 
Node *next; 
}; 
Node *head,*p,*r; //rָ������ĵ�ǰ���һ����㣬���Գ�Ϊβָ��
int x; 

void getx(Node *head,int x) 
{ Node *p; 
p=head->next; 
while((p->data!=x)&&(p->next!=NULL))p=p->next; //�ҵ���һ���ͽ��� 
if(p->data==x)cout<<p->data<<endl; 
else cout<<x<<" not exsit!"<<endl;  
}

void getxx(Node *head,int x) 
{ Node *p; 
  p=head->next; 
  while(p->next!=NULL) //һ��һ���ж� 
  { 
    if(p->data==x)cout<<p->data<<endl;  
    p=p->next; 
   } 
   if(p->data==x)cout<<p->data<<endl; 
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

void insert(Node *head,int i,int x)//����X����i��Ԫ��֮ǰ
{ Node *p,*s;int j; 
p=head; 
j=0; 
while((p!=NULL)&&(j<i-1))//Ѱ�ҵ�i-1�����,�������ĺ��� 
{ 
p=p->next; 
j=j+1; 
} 
if(p==NULL)cout<<"no this position!"; 
else{ //���� 
s=new Node; 
s->data=x; 
s->next=p->next; 
p->next=s; 
}; 
} 

void pri(Node *head) 
{ Node *p; 
p=head->next; //ͷָ��û�����ݣ�ֻҪ�ӵ�һ����㿪ʼ�Ϳ�����} 
while(p->next!=NULL) 
{ 
cout<<p->data<<" "; 
p=p->next; 
} 
cout<<p->data<<endl; //���һ���������ݵ��������Ҳ���Ը���do-whileѭ��} 
} 

void deletei(Node *head,int i) //ɾ����i��Ԫ�� 
{ 
Node *p,*s;int j; 
p=head; 
j=0; 
while((p->next!=NULL)&&(j<i-1)) 
{ 
p=p->next; 
j=j+1; 
} //pָ���i-1����� 
if (p->next==NULL) 
cout<<"no this position!"; 
else 
{ //ɾ��p�ĺ�̽�㣬����Ϊs 
s=p->next; 
p->next=p->next->next; //��p->next=s->next 
delete(s); 
} 
} 


int main() 
{ 
cin>>x; 
head=new Node; //����ͷ��� 
r=head; 
while(x!=-1) //���������-1 
{ 
p=new Node; //������һ���½�� 
p->data=x; 
p->next=NULL; 
r->next=p; //���½�����ӵ�ǰ��������У�ʵ����r��p��ֱ��ǰ�� 
r=p; //βָ�����һ�� 
cin>>x; 
} 
p=head->next; //ͷָ��û�����ݣ�ֻҪ�ӵ�һ����㿪ʼ�Ϳ�����} 
while(p->next!=NULL) 
{ 
cout<<p->data<<" "; 
p=p->next; 
} 
cout<<p->data<<endl; //���һ���������ݵ��������Ҳ���Ը���do-whileѭ��} 
//getx(head,5);
//getxx(head,5);
//get(head,4);
//insert(head,4,88);
deletei(head,5);
pri(head);
} 

