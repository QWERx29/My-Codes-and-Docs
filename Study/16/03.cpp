#include<bits/stdc++.h>
using namespace std;
int dx[12]={-2,-2,-1,1,2,2,2,2,1,-1,-2,-2},dy[12]={-1,-2,-2,-2,-2,-1,1,2,2,2,2,1};
int s[110][110],q[10086][4];
int main()
{
	memset(s,0xff,sizeof(s));
	int x1,y1,x2,y2;
	int head=1,tail=1;
	q[1][1]=q[1][2]=1;q[1][3]=0;
	cin>>x1>>y1>>x2>>y2;
	while(head<=tail)
	{
		for(int i=0;i<=11;i++)
		{
			int x=q[head][1]+dx[i],y=q[head][2]+dy[i];
			if(x>0&&y>0)
			{
				if(s[x][y]==-1)
				{
					s[x][y]=q[head][3]+1;
					tail++;
					q[tail][1]=x;q[tail][2]=y;q[tail][3]=s[x][y];
					if(s[x1][y1]>0&&s[x2][y2]>0)
					{
						cout<<s[x1][y1]<<endl;
						cout<<s[x2][y2]<<endl;
						return 0;
					}
				}
			}
		
		}
		head++;
	}
}
