#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int n, m, x, y, ans;
int tot, cnt, top, dfn[N], low[N], col[N], siz[N], st[N];
int vis[N], dis1[N], dis2[N];
int r, r1, r2, hd[N], hd1[N], hd2[N];
struct edge
{
    int nx, to;
} e[N], e1[N], e2[N];
inline void add(int u, int v) { e[++r].nx = hd[u], e[r].to = v, hd[u] = r; }
inline void add1(int u, int v) { e1[++r1].nx = hd1[u], e1[r1].to = v, hd1[u] = r1; }
inline void add2(int u, int v) { e2[++r2].nx = hd2[u], e2[r2].to = v, hd2[u] = r2; }
inline void tarjan(int x)
{
    dfn[x] = low[x] = ++cnt;
    st[++top] = x;
    for (int i = hd[x]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[x] = min(low[x], low[v]);
        else if (!col[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (dfn[x] == low[x])
    {
        tot++;
        for (; st[top + 1] != x; --top)
            col[st[top]] = tot, siz[tot]++;
    }
}
inline void SPFA1()
{
    queue<int> q;
    memset(vis, 0, sizeof vis);
    dis1[col[1]] = siz[col[1]], q.push(col[1]), vis[col[1]] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd1[u]; i; i = e1[i].nx)
        {
            int v = e1[i].to;
            if (dis1[v] < dis1[u] + siz[v])
            {
                dis1[v] = dis1[u] + siz[v];
                if (!vis[v])
                    vis[v] = 1, q.push(v);
            }
        }
    }
}
inline void SPFA2()
{
    queue<int> q;
    memset(vis, 0, sizeof vis);
    dis2[col[1]] = siz[col[1]], q.push(col[1]), vis[col[1]] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd2[u]; i; i = e2[i].nx)
        {
            int v = e2[i].to;
            if (dis2[v] < dis2[u] + siz[v])
            {
                dis2[v] = dis2[u] + siz[v];
                if (!vis[v])
                    vis[v] = 1, q.push(v);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> x >> y, add(x, y);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        for (int i = hd[u]; i; i = e[i].nx)
        {
            int v = e[i].to;
            if (col[u] != col[v])
                add1(col[u], col[v]), add2(col[v], col[u]);
        }
    }
    SPFA1(), SPFA2();
    for (int k = 1; k <= n; k++)
    {
        if (dis1[col[k]] && !vis[col[k]])
        {
            int u = col[k];
            vis[u] = 1;
            for (int i = hd2[u]; i; i = e2[i].nx)
            {
                int v = e2[i].to;
                if (!dis2[v])
                    continue;
                ans = max(ans, dis1[u] + dis2[v] - siz[col[1]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}