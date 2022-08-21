#include<bits/stdc++.h>
using namespace std;

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

__int128 n,a[510],f[510][510];
signed main()
{
	read(n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) f[i][i+1]=0;
	for(int i=n-2;i>=1;i--)
	{
		for(int j=i+2;j<=n;j++)
		{
			for(int k=i+1;k<=j-1;k++) 
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]+a[i]*a[j]*a[k]);
		}
	}
	wt(f[1][n]);
	return 0;
}