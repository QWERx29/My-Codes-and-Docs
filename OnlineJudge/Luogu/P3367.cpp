#include<bits/stdc++.h>
#define N 961100
#define ll long long
using namespace std;
int father[N],m,n,x,y,q;
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
//	ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d%d",&q,&x,&y);
    	int r1=find(x),r2=find(y);
    	if(q==1)
    	{
    		if(r1!=r2) unionn(r1,r2);
		}
    	if(q==2)
    	{
    		if(find(x)==find(y)) printf("Y\n");
    		else printf("N\n");
		}
	}
	return 0;
}

