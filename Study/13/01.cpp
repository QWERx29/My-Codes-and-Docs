#include<bits/stdc++.h>
using namespace std;
int n,s;
bool b[11][11];
int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,1,0,-1,1,0,-1};
void go(int x,int y)
{
	if(x==1&&y==n)
	{
		s++;
		return;
	}
	int i,xx,yy;
	for(i=0;i<=7;i++)
	{	
		xx=x+dx[i];
		yy=y+dy[i];
		if(b[xx][yy])
		{
			b[xx][yy]=false;
			go(xx,yy);
			b[xx][yy]=true;
		}
	}
}
int main()
{
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
cin>>x;
b[i][j]=(x==0);
}
s=0;
b[1][1]=false;
go(1,1);
printf("%d",s);
return 0;
}

