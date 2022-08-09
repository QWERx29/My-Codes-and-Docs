#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
const int INF = 0x3f3f3f3f;
int n, p, x, y, ans, t, cnt, top, tot, r;
int hd[N], dfn[N], low[N], st[N], col[N], a[N], in[N], out[N], val[N];
struct edge
{
    int nx, to;
} e[N];
inline void adde(int u, int v)
{
    e[++t].nx = hd[u];
    e[t].to = v;
    hd[u] = t;
}
inline void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    st[++top] = u;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (!col[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        tot++;
        for (; st[top + 1] != u; --top)
            col[st[top]] = tot, a[tot] = min(a[tot], val[st[top]]);
        ;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(val, INF, sizeof val), memset(a, INF, sizeof a);
    cin >> n >> p;
    for (int i = 1; i <= p; i++)
        cin >> x >> y, val[x] = y;
    cin >> r;
    for (int i = 1; i <= r; i++)
        cin >> x >> y, adde(x, y);
    for (int i = 1; i <= n; i++)
        if (!dfn[i] && val[i] != INF)
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            cout << "NO" << endl
                 << i << endl;
            return 0;
        }
    for (int u = 1; u <= n; u++)
    {
        for (int i = hd[u]; i; i = e[i].nx)
        {
            int v = e[i].to;
            if (col[v] != col[u])
                in[col[v]]++;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= tot; i++)
        if (!in[i])
            ans += a[i];
    cout << ans << endl;
    return 0;
}