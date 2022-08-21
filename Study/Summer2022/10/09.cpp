#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 114514;

int n, k;
int a[N], f[N], c[N];

inline void upd(int x, int delta)
{
	for (; x <= n; x += x & -x)
		c[x] += delta;
}
inline int qry(int x)
{
	int ans = 0;
	for (; x; x -= x & -x)
		ans += c[x];
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], f[i] = 1;
	for (int i = 1; i <= k + 1; i++)
	{
		memset(c, 0, sizeof c);
		for (int j = 1; j <= n; j++)
		{
			int tmp = qry(a[j]);
			upd(a[j], f[a[j]]);
			f[a[j]] = tmp;
		}
	}
	cout << qry(n);
	return 0;
}