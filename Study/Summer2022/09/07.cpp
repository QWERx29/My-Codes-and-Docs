#include<bits/stdc++.h>
using namespace std;
const int N=83;
template <class T>void read(T &x)
{
	x=0;
	char c,d='0';
	c=getchar();
	while(c<'0'||c>'9') d=c,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	if(d=='-') x=-x;
}
template <class T>void wt(T x)
{
	if(x/10) wt(x/10);
	putchar(x%10+'0');
}
template <class T>void write(T x)
{
	if(x<0) x=-x,putchar('-');
	wt(x),putchar('\n');
}
int n,m,a[N];
__int128 f[2][N][N],ans;

__int128 lmax(__int128 a,__int128 b)
{
	return a>b?a:b;
}
__int128 lpow(int a,int b)
{
	__int128 res=1,tmp=a;
	while(b)
	{
		if(b&1) res*=tmp;
		tmp=tmp*tmp;
		b>>=1;
	}
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=1;j<=m;j++) read(a[j]);
		f[1][1][m+1]=a[1]*2;
		f[1][0][m]=a[m]*2;
		for(int t=2,ip=0;t<=m;t++,ip^=1)
		{
			int r=m-t+1;
			f[ip][0][r]=f[ip^1][0][r+1]+(__int128)a[r]*lpow(2,t);
			for(int l=1;l<=t;l++)
			{
				r=m-t+l+1;
				f[ip][l][r]=lmax(f[ip^1][l-1][r]+(__int128)a[l]*lpow(2,t),f[ip^1][l][r+1]+(__int128)a[r]*lpow(2,t));
			}
		}
		__int128 res=0;
		for(int j=1;j<=m;j++) res=lmax(res,f[m%2][j][j+1]);
		ans+=res;
	}
	write(ans);
	return 0;
}