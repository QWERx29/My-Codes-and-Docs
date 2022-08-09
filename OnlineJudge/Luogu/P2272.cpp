#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, m, s, t, x, y, mod;
int tot, cnt, top;
int r1, r2, hd1[N], hd2[N];
int vis[N], dis[N];
int ans1, ans2;
int val[N], sum[N], st[N], dfn[N], low[N], col[N], siz[N];
struct edge
{
    int nx, to, val;
} e1[N], e2[N];
inline void add1(int u, int v)
{
    e1[++r1].nx = hd1[u];
    e1[r1].to = v, hd1[u] = r1;
}
inline void add2(int u, int v)
{
    e2[++r2].nx = hd2[u];
    e2[r2].to = v, hd2[u] = r2;
}
inline void tarjan(int x)
{
    dfn[x] = low[x] = ++cnt;
    st[++top] = x;
    for (int i = hd1[x]; i; i = e1[i].nx)
    {
        int v = e1[i].to;
        if (!dfn[v])
            tarjan(v), low[x] = min(low[x], low[v]);
        else if (!col[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x])
    {
        ++tot;
        for (; st[top + 1] != x; --top)
            col[st[top]] = tot, siz[tot]++;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; i++)
        cin >> x >> y, add1(x, y);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        dis[u] = siz[u], sum[u] = 1;
        for (int i = hd1[u]; i; i = e1[i].nx)
        {
            int v = e1[i].to;
            if (col[u] != col[v])
                add2(col[u], col[v]);
        }
    }
    for (int u = tot; u >= 1; u--)
    {
        for (int i = hd2[u]; i; i = e2[i].nx)
        {
            int v = e2[i].to;
            if (vis[v] == u)
                continue;
            vis[v] = u;
            if (dis[v] < dis[u] + siz[v])
                dis[v] = dis[u] + siz[v], sum[v] = sum[u];
            else if (dis[v] == dis[u] + siz[v])
                sum[v] = (sum[u] + sum[v]) % mod;
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        if (dis[i] > ans1)
            ans1 = dis[i], ans2 = sum[i];
        else if (dis[i] == ans1)
            ans2 = (ans2 + sum[i]) % mod;
    }
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}