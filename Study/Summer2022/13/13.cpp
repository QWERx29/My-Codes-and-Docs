#include <algorithm>
#include <cstdio>
#define int long long
const int N = 1e6 + 5;
const int M = 1.8e6 + 5;
const int INF = 0x3f3f3f3f3f3f3f3fll;
namespace FastIO
{
	template <class T>
	void read(T &x)
	{
		x = 0;
		char c = getchar(), d = '0';
		while (c < '0' || c > '9')
			d = c, c = getchar();
		while (c >= '0' && c <= '9')
			x = (x << 3) + (x << 1) + c - '0', c = getchar();
		if (d == '-')
			x = -x;
	}
	template <class T>
	inline void wt(T x)
	{
		if (x / 10)
			wt(x / 10);
		putchar(x % 10 + '0');
	}
	template <class T>
	inline void wtln(T x)
	{
		if (x < 0)
			x = -x, putchar('-');
		wt(x), putchar('\n');
	}
	template <class T>
	inline const T &min(const T &x, const T &y) { return x < y ? x : y; }
	template <class T>
	inline const T &max(const T &x, const T &y) { return x > y ? x : y; }
	template <class T>
	inline void swap(T &x, T &y) { x ^= y ^= x ^= y; }
}
using namespace FastIO;
struct edge
{
	int fr, to, val, nx;
	inline bool operator<(const edge &b) const { return val < b.val; }
} e[N << 1], a[M];
int tot, cnt, n, h[N], m, fa[N], bz[N][19], maxi[N][19], mini[N][19], dep[N];
inline void adde(int u, int v, int w)
{
	e[++tot].fr = u;
	e[tot].to = v;
	e[tot].val = w;
	e[tot].nx = h[u];
	h[u] = tot;
}

inline void dfs(int u, int fa)
{
	bz[u][0] = fa;
	for (register int i = h[u]; i; i = e[i].nx)
	{
		register int v = e[i].to;
		if (v == fa)
			continue;
		dep[v] = dep[u] + 1ll;
		maxi[v][0] = e[i].val;
		mini[v][0] = -INF;
		dfs(v, u);
	}
}
inline void cal()
{
	for (register int i = 1; i <= 18; i++)
	{
		for (register int j = 1; j <= n; j++)
		{
			bz[j][i] = bz[bz[j][i - 1]][i - 1];
			maxi[j][i] = max(maxi[j][i - 1], maxi[bz[j][i - 1]][i - 1]);
			mini[j][i] = max(mini[j][i - 1], mini[bz[j][i - 1]][i - 1]);
			if (maxi[j][i - 1] > maxi[bz[j][i - 1]][i - 1])
				mini[j][i] = max(mini[j][i], maxi[bz[j][i - 1]][i - 1]);
			else if (maxi[j][i - 1] < maxi[bz[j][i - 1]][i - 1])
				mini[j][i] = max(mini[j][i], maxi[j][i - 1]);
		}
	}
}
inline int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	for (register int i = 18; ~i; i--)
	{
		if (dep[bz[x][i]] >= dep[y])
			x = bz[x][i];
	}
	if (x == y)
		return x;
	for (register int i = 18; ~i; i--)
	{
		if (bz[x][i] ^ bz[y][i])
			x = bz[x][i], y = bz[y][i];
	}
	return bz[x][0];
}
inline int qmax(int u, int v, int res)
{
	register int ans = -INF;
	for (register int i = 18; ~i; i--)
	{
		if (dep[bz[u][i]] >= dep[v])
		{
			if (res != maxi[u][i])
				ans = max(ans, maxi[u][i]);
			else
				ans = max(ans, mini[u][i]);
			u = bz[u][i];
		}
	}
	return ans;
}
inline int find(int x)
{
	return x == fa[x] ? x : x = find(fa[x]);
}
bool b[M];
inline void work()
{
	register int ans = INF;
	for (register int i = 1; i <= m; i++)
	{
		if (!b[i])
		{
			register int maxu = qmax(a[i].fr, lca(a[i].fr, a[i].to), a[i].val), maxv = qmax(a[i].to, lca(a[i].fr, a[i].to), a[i].val);
			if (max(maxu, maxv) != a[i].val)
				ans = min(ans, cnt - max(maxu, maxv) + a[i].val);
		}
	}
	wtln(ans);
}
signed main()
{
	read(n), read(m);
	for (register int i = 1; i <= m; i++)
		read(a[i].fr), read(a[i].to), read(a[i].val);
	std::sort(a + 1, a + m + 1);
	for (register int i = 1; i <= n; i++)
		fa[i] = i;
	for (register int i = 1; i <= m; i++)
	{
		register int f1 = find(a[i].fr), f2 = find(a[i].to);
		if (f1 != f2)
		{
			cnt += a[i].val;
			fa[f1] = f2;
			adde(a[i].fr, a[i].to, a[i].val);
			adde(a[i].to, a[i].fr, a[i].val);
			b[i] = 1;
		}
	}
	mini[1][0] = -INF;
	dep[1] = 1;
	dfs(1, -1);
	cal();
	work();
	return 0;
}
