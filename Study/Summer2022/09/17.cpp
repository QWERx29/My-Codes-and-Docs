#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 11451;
const int INF = 0x7fffffff;
struct edge
{
    int nx, to;
} e[N << 1];
int n, m, a[N];
int rt, cnt, hd[N];
int f[N][2];
inline void adde(int u, int v)
{
    e[++cnt] = {hd[u], v};
    hd[u] = cnt;
}
inline void dfs(int u, int pre)
{
    if (u <= n)
        return;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v != pre)
        {
            dfs(v, u);
            f[u][0] += min(f[v][0] - 1, f[v][1]);
            f[u][1] += min(f[v][1] - 1, f[v][0]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    rt = n + 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < m; i++)
        cin >> u >> v, adde(u, v), adde(v, u);
    for (int i = 1; i <= m; i++)
    {
        f[i][0] = f[i][1] = 1;
        if (i <= n)
            f[i][(!a[i])] = INF;
    }
    dfs(rt, rt);
    cout << min(f[rt][0], f[rt][1]) << '\n';
    return 0;
}