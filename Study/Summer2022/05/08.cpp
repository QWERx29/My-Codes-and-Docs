#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int MOD = 2009;

int n, t, m;

struct mat
{
	int a[N][N];
	int x, y;
	mat() {}
	inline mat(const int &_x, const int &_y) : x(_x), y(_y)
	{
		memset(a, 0, sizeof(a));
	}
	inline void clear()
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= x; i++)
			a[i][i] = 1;
	}
	inline mat operator*(const mat &b) const
	{
		mat c(x, b.y);
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= b.y; j++)
			{
				for (int k = 1; k <= y; k++)
					c.a[i][j] += a[i][k] * b.a[k][j];
				c.a[i][j] %= MOD;
			}
		return c;
	}
	inline mat operator^(int p) const
	{
		mat c(x, y), q = *this;
		c.clear();
		for (; p; p >>= 1, q = q * q)
			if (p & 1)
				c = c * q;
		return c;
	}
} f;

inline int pos(const int &q, const int &w)
{
	return q + w * n;
}

int main()
{
	cin >> n >> t;
	m = n * 9;
	f = mat(m, m);
	int x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 8; j++)
			f.a[pos(i, j)][pos(i, j - 1)] = 1;
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &x);
			if (x)
				f.a[i][pos(j, x - 1)] = 1;
		}
	}
	f = f ^ t;
	cout << f.a[1][n] << endl;
	return 0;
}