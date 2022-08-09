#include <bits/stdc++.h>
using namespace std;
const int N = 5e7 + 50;
int dep[N], fa[N], sn[N], tp[N], sz[N], hd[N];
int n, m, cnt, ans[N], a[N];
struct edge
{
    int to, nx;
} e[N];
inline void adde(int u, int v)
{
    e[++cnt].nx = hd[u];
    e[cnt].to = v, hd[u] = cnt;
}
inline void dfs1(int u)
{
    sz[u] = 1;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (dep[v])
            continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[sn[u]])
            sn[u] = v;
    }
}
inline void dfs2(int u, int top)
{
    tp[u] = top;
    if (!sn[u])
        return;
    dfs2(sn[u], top);
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == fa[u] || v == sn[u])
            continue;
        dfs2(v, v);
    }
}
inline int lca(int u, int v)
{
    while (tp[u] != tp[v])
    {
        if (dep[tp[u]] < dep[tp[v]])
            swap(u, v);
        u = fa[tp[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
inline void work(int u, int pa)
{
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == pa)
            continue;
        work(v, u);
        ans[u] += ans[v];
    }
}
signed main()
{
    int x, y;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> x >> y, adde(x, y), adde(y, x);
    dep[1] = 1;
    dfs1(1), dfs2(1, 0);
    for (int i = 1; i < n; i++)
    {
        int u = a[i], v = a[i + 1];
        int t = lca(u, v);
        ans[fa[t]]--, ans[t]--, ans[u]++, ans[v]++;
    }
    work(1, 0);
    for (int i = 2; i <= n; i++)
        ans[a[i]]--;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}