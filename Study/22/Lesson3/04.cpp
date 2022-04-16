#include<bits/stdc++.h>
#define N 961100
#define ll long long
using namespace std;
int father[N],m,n,x,y,q,w;
char ch;
int find(int x)
{
	if(father[x]!=x) return father[x]=find(father[x]);
	else return father[x];
} 
void unionn(int x,int y)
{
	father[y]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=2*n;i++) father[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>w>>x>>y;
		int r1=find(x),r2=find(y);
		int r3=find(x+n),r4=find(y+n);
		if(w==0) unionn(r1,r2);
		if(w==1) 
		{
			unionn(r2,r3);
			unionn(r1,r4);
		}
	}
	for(int i=1;i<=n;i++) if(father[i]==i) q++;
	cout<<q;
	return 0;
}

