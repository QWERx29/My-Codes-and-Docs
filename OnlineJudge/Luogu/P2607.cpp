#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1145141;
struct edge
{
    int nx, to;
} e[N << 1];
bool vis[N];
int n, s, x1, x2, E, w[N];
int cnt, hd[N];
ll f[N][2], ans;
inline void adde(int u, int v) { e[cnt] = {hd[u], v}, hd[u] = cnt++; }

inline void dp(int u, int pre = -1)
{
    vis[u] = 1;
    for (int i = hd[u]; ~i; i = e[i].nx)
    {
        if ((i ^ 1) == pre)
            continue;
        int v = e[i].to;
        if (vis[v])
        {
            x1 = u, x2 = v, E = i;
            continue;
        }
        dp(v, i);
    }
}
inline void dfs(int u, int pre = -1)
{
    f[u][0] = 0, f[u][1] = w[u];
    for (int i = hd[u]; ~i; i = e[i].nx)
    {
        if ((i ^ 1) == pre)
            continue;
        if (i == E || (i ^ 1) == E)
            continue;
        int v = e[i].to;
        dfs(v, i);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][1], f[v][0]);
    }
}
signed main()
{
    memset(hd, -1, sizeof hd);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, x; i <= n; i++)
        cin >> w[i] >> x, adde(i, x), adde(x, i);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dp(i);
        dfs(x1);
        ll tmp = f[x1][0];
        dfs(x2);
        tmp = max(tmp, f[x2][0]);
        ans += tmp;
    }
    cout << ans << '\n';
    return 0;
}