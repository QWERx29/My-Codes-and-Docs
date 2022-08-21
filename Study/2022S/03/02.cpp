#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500150;

struct node{
	map<int,int> c;
	int size;
	int tag=0;
}a[N];
int tot=1,rot=1;
int n,m;
char s[N];

inline int read()
{
    int ans=0;
    char c;
    while(!(c>='0'&&c<='9')) c = getchar();
    while(c>='0'&&c<='9') 
	{
        ans=(ans<<1)+(ans<<3)+c-48;
        c=getchar();
    }
    return ans;
}
inline void insert(char* s)
{
	int pos=rot,val;
	for(;*s!=-1;s++)
	{
		val=(*s);
		if(!a[pos].c[val]) a[pos].c[val]=++tot;
		pos=a[pos].c[val];
		a[pos].size++;
	}
	a[pos].tag++;
}
inline int find(char* s)
{
	int pos=rot,val,ans=0;
	bool end=false;
	for(;*s!=-1;s++)
	{
		val=(*s);
		if(!a[pos].c[val]) 
		{
			end=true;
			break;
		}
		pos=a[pos].c[val];
		ans+=a[pos].tag;
	}
	if(end==false) ans+=a[pos].size-a[pos].tag;
	return ans;
}
inline void get()
{
//	memset(s,' ',sizeof(s));
	int len;
	len=read();
	for(int j=1;j<=len;j++) s[j]=read();
	s[len+1]=-1;
}


signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		get();
		insert(s+1);
	}
	for(int i=1;i<=m;i++)
	{
		get();
		printf("%d\n",find(s+1));
	}
	return 0;
}