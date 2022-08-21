#include<bits/stdc++.h>
using namespace std;
const int N=26,M=1e6+10,n=26;
int T,m,p[N];
int in[N],out[N];
bool st[N];
char str[1010];
int find(int x)
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
bool cnt()
{
	int rt=-1;
	for(int i=0;i<n;i++)
	{
		if(st[i])
		{
			if(rt==-1) rt=find(i);
			if(rt!=find(i)) return 0;
		}
	}
	return 1;
}
bool judge()
{
	int st=0,ed=0;
	for(int i=0;i<n;i++)
	{
		if(in[i]!=out[i])
		{
			if(in[i]+1==out[i]) st++;
			else if(out[i]+1==in[i]) ed++;
			else return 0;
		}
	}
	if(!st&&!ed) return 1;
	if(st==1&&ed==1) return 1;
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		for(int i=0;i<n;i++) p[i]=i;
		memset(st,false,sizeof st);
		memset(in,0,sizeof in),memset(out,0,sizeof out);
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>str;
			int l=strlen(str);
			int a=str[0]-'a',b=str[l-1]-'a';
			in[b]++,out[a]++;
			st[b]=st[a]=true;
			p[find(a)]=find(b);
		}
		if(cnt()&&judge()) cout<<"Ordering is possible.\n";
		else cout<<"The door cannot be opened.\n";
	}
	return 0;
}