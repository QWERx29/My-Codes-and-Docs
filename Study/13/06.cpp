#include<bits/stdc++.h>
using namespace std;
int q[8]={1,2,2,1,-1,-2,-2,-1},w[8]={-2,-1,1,2,2,1,-1,-2};
int tot=0,a[101][101]={0},n;
bool b[101][101]={0};
void search(int i,int j,int v)
{
	int k,x,y;
	if(v>25) tot++;
	for(k=0;k<=7;k++)
	{
		x=i+q[k];y=j+w[k];
		if(x<=n&&x>=1&&y<=n&&y>=1&&(!b[x][y]))
		{
			b[x][y]=1;
			a[x][y]=v;
			search(x,y,v+1);
			b[x][y]=0;
			a[x][y]=0;
		}
	}
}

int main()
{
	cin>>n;
	a[1][1]=1;b[1][1]=1;
	search(1,1,2);
	cout<<tot;
	return 0;
}
