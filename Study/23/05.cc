#include<bits/stdc++.h>
using namespace std;
int r,c,q[10086];
char a[10086][80],b[80][10086];
void _getx(int l) 
{
	int j=-1;
	q[0]=-1;
	for (int i=1;i<l;i++) 
	{
		while(j>-1&&strcmp(a[j+1],a[i])) j=q[j];
		if(!strcmp(a[j+1],a[i])) j++;
		q[i]=j;
	}
}
void _gety(int l) 
{
	int j=-1;
	q[0]=-1;
	for (int i=1;i<l;i++) 
	{
		while(j>-1&&strcmp(b[j+1],b[i])) j=q[j];
		if(!strcmp(b[j+1],b[i])) j++;
		q[i]=j;
	}
}
void _rotate(int x,int y) 
{
	for(int i=0;i<y;i++) 
	{
		for(int j=0;j<x;j++) b[i][j]=a[j][i];
		b[i][x]='\0';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>r>>c;
	for(int i=0;i<r;i++) cin>>a[i];
	_getx(r);
	int ans=r-q[r-1]-1;
	_rotate(r,c);
	_gety(c);
	ans*=(c-q[c-1]-1);
	cout<<ans;
	return 0;
}