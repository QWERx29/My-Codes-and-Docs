#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2022;
int n, k, cnt;
ll dp[N][N], ans;
int siz[N], hd[N];
struct edge
{
    int nx, to, val;
} e[N << 1];
inline void adde(int u, int v, int w) { e[++cnt] = {hd[u], v, w}, hd[u] = cnt; }
inline ll weight(ll siz, ll blk) { return blk * (k - blk) + (siz - blk) * (n - siz - k + blk); }
inline void dfs(int u, int pre = 0)
{
    siz[u] = 1;
    dp[u][0] = dp[u][1] = 0;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == pre)
            continue;
        dfs(v, u);
        for (int o = min(siz[u], k); o >= 0; o--)
            for (int r = min(siz[v], k - o); r >= 0; r--)
                dp[u][o + r] = max(dp[u][o + r], dp[u][o] + dp[v][r] + e[i].val * weight(siz[v], r));
        siz[u] += siz[v];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(dp, 0xc0, sizeof dp);
    cin >> n >> k;
    for (int i = 1, x, y, z; i < n; i++)
        cin >> x >> y >> z, adde(x, y, z), adde(y, x, z);
    dfs(1);
    cout << dp[1][k] << '\n';
    return 0;
}