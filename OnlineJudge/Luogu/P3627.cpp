#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, m, s, t, x, y, ans;
int tot, cnt, top;
int r1, r2, hd1[N], hd2[N];
int val[N], a[N], d[N], st[N], dfn[N], low[N], col[N], vis[N], dis[N];
struct edge
{
    int nx, to, val;
} e1[N], e2[N];
inline void add1(int u, int v)
{
    e1[++r1].nx = hd1[u];
    e1[r1].to = v, hd1[u] = r1;
}
inline void add2(int u, int v, int w)
{
    e2[++r2].nx = hd2[u];
    e2[r2].to = v, e2[r2].val = w;
    hd2[u] = r2;
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
            col[st[top]] = tot, val[tot] += a[st[top]];
    }
}
inline void SPFA()
{
    queue<int> q;
    dis[col[s]] = val[col[s]];
    q.push(col[s]);
    vis[col[s]] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd2[u]; i; i = e2[i].nx)
        {
            int v = e2[i].to;
            if (dis[v] < dis[u] + e2[i].val)
            {
                dis[v] = dis[u] + e2[i].val;
                if (!vis[v])
                    vis[v] = 1, q.push(v);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> x >> y, add1(x, y);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        for (int i = hd1[u]; i; i = e1[i].nx)
        {
            int v = e1[i].to;
            if (col[u] != col[v])
                add2(col[u], col[v], val[col[v]]);
        }
    }
    cin >> s >> t;
    SPFA();
    for (int i = 1; i <= t; i++)
        cin >> x, ans = max(ans, dis[col[x]]);
    cout << ans << endl;
    return 0;
}