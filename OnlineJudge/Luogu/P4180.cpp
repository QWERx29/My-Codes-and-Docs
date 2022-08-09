#include <cstdio>
#include <algorithm>
#define int long long
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
const int MAXN = 100005;
const int INF = 1145141919180;
int n, m, tot, ans = INF, f[MAXN], p[MAXN], dep[MAXN];
int fa[MAXN][20], Max[MAXN][20], sub[MAXN][20];
int mst;
struct edge
{
    int v, c, next;
} e[2 * MAXN];
struct node
{
    int u, v, c;
    bool operator<(const node &x) const { return c < x.c; }
} a[3 * MAXN];
int op(int a, int b, int lim)
{
    if (a >= lim)
        return b >= lim ? 0 : b;
    if (b >= lim)
        return a >= lim ? 0 : a;
    return max(a, b);
}
int findSet(int x)
{
    if (x ^ p[x])
        p[x] = findSet(p[x]);
    return p[x];
}
void MST()
{
    std::sort(a + 1, a + 1 + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = a[i].u, v = a[i].v, c = a[i].c, x = findSet(u), y = findSet(v);
        if (x == y)
            continue;
        e[++tot] = edge{v, c, f[u]}, f[u] = tot;
        e[++tot] = edge{u, c, f[v]}, f[v] = tot;
        mst += c;
        p[x] = y;
    }
}
void dfs(int u, int par)
{
    fa[u][0] = par;
    dep[u] = dep[par] + 1;
    for (int i = 1; i < 20; i++)
    {
        int pos = fa[u][i - 1];
        Max[u][i] = max(Max[u][i - 1], Max[pos][i - 1]);
        sub[u][i] = max(sub[u][i - 1], sub[pos][i - 1]);
        fa[u][i] = fa[pos][i - 1];
        if (Max[u][i - 1] ^ Max[pos][i - 1])
            sub[u][i] = max(sub[u][i], min(Max[u][i - 1], Max[pos][i - 1]));
    }
    for (int i = f[u]; i; i = e[i].next)
        if (e[i].v ^ par)
        {
            Max[e[i].v][0] = e[i].c;
            sub[e[i].v][0] = -INF;
            dfs(e[i].v, u);
        }
}
void upd(int &x, int u, int i, int lim)
{
    x = op(x, Max[u][i], lim);
    x = op(x, sub[u][i], lim);
}
int lca(int u, int v, int lim)
{
    int res = -INF;
    for (int i = 19; i >= 0; i--)
    {
        if (dep[fa[u][i]] >= dep[v])
            upd(res, u, i, lim), u = fa[u][i];
        if (dep[fa[v][i]] >= dep[u])
            upd(res, v, i, lim), v = fa[v][i];
    }
    if (u == v)
        return res;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] ^ fa[v][i])
        {
            upd(res, u, i, lim);
            upd(res, v, i, lim);
            u = fa[u][i], v = fa[v][i];
        }
    upd(res, u, 0, lim);
    upd(res, v, 0, lim);
    return res;
}
signed main()
{
    read(n), read(m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        read(u), read(v), read(c);
        a[i] = node{u, v, c};
    }
    MST();
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        int val = lca(a[i].u, a[i].v, a[i].c);
        if (val != -INF)
            ans = min(ans, a[i].c - val);
    }
    ans += mst;
    wtln(ans);
    return 0;
}
