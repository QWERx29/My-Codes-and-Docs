#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool b[21]={0};   
int toal=0,a[21]={0},n;  //toal������¼������   ����a��¼���� 
int search(int); 
int print(); //������� 
bool pd(int ,int);  //�ж��������ֺ��Ƿ�Ϊ���� 
int main()
{
	cin>>n;
	search(1);
	 //�ӵ�һλ��ʼ�� 
	cout<<toal<<endl;
 } 
int search(int t)
{
	int i;
	for(i=1;i<=n;i++)   //ÿ��λ�ö�����n���� 
		if((pd(a[t-1],i))&&(!b[i]))   //���� 1.����ߺ�Ϊ����2.δʹ�ù� 
		{
			a[t]=i;
			b[i]=1;  
			if(t==n) 
			{
				if(pd(a[n],a[1])) print();
			}
			else search(t+1);
			b[i]=0; 
			  //����  ��b[i]���  ���¿�ʼ��һ�鷽�� 
			
		}
}
int print()  //������� 
{
	toal++;
	cout<<"<"<<toal<<">";
	for(int j=1;j<=n;j++)
		cout<<a[j]<<" ";
	cout<<endl; 
}
bool pd(int x,int y)  //�ж����������Ƿ�Ϊ���� 
{
	int k=2,q=x+y;
	while(k<=sqrt(q)&&q%k!=0)   //ֻ���жϲ�����sqrt(i)�����ܷ������� 
		k++;
	if(k>sqrt(q))
		return 1;
	else 
		return 0;
}

