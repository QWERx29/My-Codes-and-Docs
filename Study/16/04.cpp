#include<bits/stdc++.h>
using namespace std;
int dx[9]={0,0,1,0,-1,1,1,-1,-1},dy[9]={0,1,0,-1,0,1,-1,-1,1};
int n,ex,ey,sx,sy,head,tail,x,y,a[110],b[110],p[110],m[51][51];
int sum;
bool f;
void print(int d)
{
	if(p[d]!=0) print(p[d]);
	sum++;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cin>>m[i][j];
	}
	sx=sy=1;ex=1;ey=n;
	head=0;tail=1;
	f=0;
	m[sx][sy]=1;
	a[tail]=sx;b[tail]=sy;p[tail]=0;
	while(head!=tail)
	{
		head++;
		for(int i=1;i<=8;i++)
		{
			x=a[head]+dx[i];
			y=b[head]+dy[i];
			if(x>0&&x<=n&&y>0&&y<=n&&m[x][y]==0)
			{
				tail++;
				a[tail]=x;b[tail]=y;p[tail]=head;
				m[x][y]=1;
				if(x==ex&&y==ey)
				{
					f=1;
					print(tail);
					break;
				}
			}
		}
		if(f) break;
	}
	if(!f) cout<<"no way."<<endl;
	else cout<<sum-1;
	return 0;
}
