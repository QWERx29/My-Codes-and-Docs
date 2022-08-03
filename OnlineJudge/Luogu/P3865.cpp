#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005,L=20;
int n,m;
int st[N][L],lg[N],val[N];
inline void init(int n)
{
	lg[0]=-1;
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1,st[i][0]=val[i];
	for(int j=0;j+1<L;j++)
	{
		for(int i=1;i+(1<<(j+1))-1<=n;i++)
			st[i][j+1]=max(st[i][j],st[i+(1<<j)][j]);
	}
}
inline int query(int l,int r)
{
	int g=lg[r-l+1];
	return max(st[l][g],st[r-(1<<g)+1][g]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	init(n);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}