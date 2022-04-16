#include<bits/stdc++.h>
using namespace std;
int a,n,m,x;
int main()
{
	cin>>a>>n>>m>>x;
	if(n<=5)
	{
		if(n==2||n==3) cout<<a;
		else if(n==4)
		{
			if(x==1||x==2) cout<<a;
			else if(x==3) cout<<a*2;
		}
		else if(n==5)
		{
			if(x==1||x==2) cout<<a;
			else if(x==3) cout<<a*2;
			else if(x==4) cout<<(m-a*3)/2+a*2;
		}
	}
	else
	{
		int q=1,w=0,e=0,s1=0;
		for(int i=1;i<=n-5;i++)
		{
			e=q+w;
			s1+=e;
			q=w;w=e;
		}
		int s2=s1+2;
		int r=0,t=1,y=0,s3=0;
		for(int i=1;i<=n-5;i++)
		{
			y=r+t;
			s3+=y;
			r=t;t=y;
		}
		int s4=s3+1;
		int s=(m-s2*a)/s4;
		w=e=r=y=s1=s3=0;
		q=t=1;
		if(x<=5)
		{
			if(x==1||x==2) cout<<a;
			else if(x==3) cout<<a*2;
			else if(x==4) cout<<s+a*2;
			else cout<<s*2+a*3;
		}
		else
		{
			for(int i=1;i<=x-4;i++)
			{
				e=q+w;
				s1+=e;
				q=w;w=e;
			}
			s1+=2;
			for(int i=1;i<=x-4;i++)
			{
				y=r+t;
				s3+=y;
				r=t;t=y;
			}
			s3+=1;
			cout<<s1*a+s3*s;
		}
	}
}
