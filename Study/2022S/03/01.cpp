#include<bits/stdc++.h>
using namespace std;

struct node{
	int c[128];
	bool tag=0;
}a[1000005];
int tot=1,rot=1;
void insert(char* s)
{
	int pos=rot,val;
	for(;*s;s++)
	{
		val=(*s);
		if(!a[pos].c[val]) a[pos].c[val]=++tot;
		pos=a[pos].c[val];
	}
	a[pos].tag++;
}
int find(char* s)
{
	int pos=rot,val;
	for(;*s;s++)
	{
		val=(*s);
		if(!a[pos].c[val]) return -1;
		pos=a[pos].c[val];
	}
	return a[pos].tag;
}

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		char s[205],c;
		memset(s,' ',sizeof(s));
		cin>>c;
		if(c=='a') 
		{
			getchar();getchar();getchar();
			cin.getline(s,sizeof(s));
			insert(s);
		}
		else
		{
			getchar();getchar();getchar();getchar();
			cin.getline(s,sizeof(s));
			int flag=find(s);
			if(flag==1) cout<<"yes"<<endl;
			if(flag==-1||flag==0) cout<<"no"<<endl;
		}
	}
	return 0;
}