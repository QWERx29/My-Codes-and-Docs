#include<bits/stdc++.h>
using namespace std;
int a[10086],b[10086],c[10086],d,i;
void init(int a[])
{
	string s;
	cin>>s;
	a[0]=s.length();
	for(i=1;i<=a[0];i++)
	a[i]=s[a[0]-i]-'0';
}
void print(int a[])
{
	if(a[0]==0)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=a[0];i>0;i--) cout<<a[i];
	cout<<endl;
	return;
}
int compare (int a[],int b[])  
{    
	int i;
	if(a[0]>b[0]) return 1;                    
	if(a[0]<b[0]) return -1;                  
	for(i=a[0];i>0;i--)                          
	{
		if(a[i]>b[i]) return 1; 
		if(a[i]<b[i]) return -1;
	} 
	return 0;                                         
}
void numcpy(int p[],int q[],int det)      
{
	for(int i=1;i<=p[0];i++) q[i+det-1]=p[i];
	q[0]=p[0]+det-1;
}
void jian(int a[],int b[])              
{ 
	int flag,i; 
	flag=compare(a,b);              
	if(flag==0) 
	{
		a[0]=0;
		return;
	}  
	if(flag==1)                             
	{
		for(i=1;i<=a[0];i++) 
		{
			if(a[i]<b[i])
			{ 	
				a[i+1]--;
				a[i]+=10;
			}         
			a[i]-=b[i];
		} 
		while(a[0]>0&&a[a[0]]==0) a[0]--;             
		return;
	} 
} 
void chugao(int a[],int b[],int c[])
{
	int tmp[10086]; 
	c[0]=a[0]-b[0]+1;
	for(int i=c[0];i>0;i--)
	{
		memset(tmp,0,sizeof(tmp));                             
		numcpy(b,tmp,i);
		while(compare(a,tmp)>=0)
		{
			c[i]++;
			jian(a,tmp);
		} 
	}
	while(c[0]>0&&c[c[0]]==0) c[0]--;
	return ;
}
int main()
{
	init(a);init(b);
	chugao(a,b,c);
	print(c);
//	print(a);
	return 0;
}
