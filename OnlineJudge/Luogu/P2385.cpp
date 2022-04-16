#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
struct node
{
	int x;
	int y;
	int s;
}q[1000000];
int main()
{
	int n,m,m1,m2;
	int head=1,tail=0;
	int endx,endy;
	cin>>n>>m>>m1>>m2;
	int fx[8]={m2,m2,-m2,-m2,m1,m1,-m1,-m1};
	int fy[8]={m1,-m1,m1,-m1,m2,-m2,m2,-m2};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			if(x==1) a[i][j]=0;
			if(x==0||x==2) a[i][j]=1;
			if(x==3)
			{
				a[i][j]=1;
				q[++tail].x=i;
				q[tail].y=j;
				q[tail].s=0;
			}
			if(x==4)
			{
				endx=i;
				endy=j;
				a[i][j]=0;
			}
		}
	}
	for(head=1;head<=tail;head++)
	{
		for(int i=0;i<8;i++)
		{
			int xx=q[head].x+fx[i],yy=q[head].y+fy[i];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(a[xx][yy]==0)
			{
				a[xx][yy]=1;
				q[++tail].x=xx;
				q[tail].y=yy;
				q[tail].s=q[head].s+1;
				if(xx==endx && yy==endy)
				{
					cout << q[tail].s;
					return 0;
				}
			}
		}
	}
	return 0;
}

