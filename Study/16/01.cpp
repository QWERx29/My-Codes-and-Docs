#include<bits/stdc++.h>
using namespace std;
int q[10][10],a[110],b[110],sum;
bool s[9]={false};
void bfs()
{
	int head=0,tail=1,i;
	a[1]=1;b[1]=0;s[1]=1;
	do
	{
		head++;
		for(i=1;i<=8;i++)
		{
			if(q[a[head]][i]==0&&s[i]==0)
			{
				tail++;
				a[tail]=i;
				b[tail]=head;
				s[i]=1;
				if(i==8) 
				{
					//cout<<char(a[t]+64);
					while(b[tail])
					{
						tail=b[tail];
						sum++;
						//cout<<"-"<<char(a[t]+64);
					}
					head=tail;
					break;
				}
				
			}
		}
	}while(head<tail);
}
int main()
{
	memset(s,false,sizeof(s));
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++) cin>>q[i][j];
	}
	bfs();
	cout<<endl<<sum-1;
	return 0;
}
