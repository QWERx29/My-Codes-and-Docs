// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int m,c,s,d;
bool flag=true;
int main()
{
	for(int i=1;i<=12;i++)
	{
		m+=300;cin>>c;m-=c;
		if(m<0)
		{
			flag=false;d=i;
			break;
		}
		s+=m/100;
		m%=100;
	}
	if(flag==true)
	{
		m+=s*120;
		cout<<m;
	}
	else
		cout<<-d;
}
