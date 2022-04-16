#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool b[21]={0};   
int toal=0,a[21]={0},n;  //toal用来记录方案数   数组a记录方案 
int search(int); 
int print(); //输出方案 
bool pd(int ,int);  //判断两个数字和是否为素数 
int main()
{
	cin>>n;
	search(1);
	 //从第一位开始找 
	cout<<toal<<endl;
 } 
int search(int t)
{
	int i;
	for(i=1;i<=n;i++)   //每个位置都尝试n个数 
		if((pd(a[t-1],i))&&(!b[i]))   //条件 1.和左边和为素数2.未使用过 
		{
			a[t]=i;
			b[i]=1;  
			if(t==n) 
			{
				if(pd(a[n],a[1])) print();
			}
			else search(t+1);
			b[i]=0; 
			  //回溯  将b[i]清空  重新开始下一组方案 
			
		}
}
int print()  //输出方案 
{
	toal++;
	cout<<"<"<<toal<<">";
	for(int j=1;j<=n;j++)
		cout<<a[j]<<" ";
	cout<<endl; 
}
bool pd(int x,int y)  //判断两个数和是否为素数 
{
	int k=2,q=x+y;
	while(k<=sqrt(q)&&q%k!=0)   //只需判断不大于sqrt(i)的数能否将其整除 
		k++;
	if(k>sqrt(q))
		return 1;
	else 
		return 0;
}

