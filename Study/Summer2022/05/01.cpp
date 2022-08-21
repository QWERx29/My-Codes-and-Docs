#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int MOD=1e9+7;

struct mat{
	int n,m;
	ll a[N][N];
	inline mat(int op=0)
	{
        memset(a,0,sizeof(a));
        if(op)for(int i=0;i<n;++i)a[i][i]=1;
    }
	inline const ll* operator[](int x) const { return a[x]; }
	inline ll* operator[](int x) { return a[x]; }
	inline mat operator*(const mat& b)const
	{
		mat c;
		c.n=n,c.m=b.m;
		for(int i=0;i<n;i++)
			for(int k=0;k<m;k++)
			{
				ll tmp=a[i][k];
				for(int j=0;j<b.m;j++)
					c[i][j]=(c[i][j]+tmp*b[k][j])%MOD;
			}
		return c;
	}
	void input()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) 
				cin>>a[i][j];
	}
	void output()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)	
				cout<<(a[i][j]+MOD)%MOD<<" ";
			cout<<"\n";
		}	
	}
}a,b;

int main()
{
	cin>>a.n>>a.m>>b.m;
	b.n=a.m;
	a.input(),b.input();
	(a*b).output();
	return 0;
}