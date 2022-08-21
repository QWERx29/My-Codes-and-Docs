#include <bits/stdc++.h>
using namespace std;
const int N = 12;
const int S = 1 << N;
int n, m, tot;
int v[N + 1][N + 1], dp[2][S], dis[S][S], ds[N + 1][S], vld[S], lg[S];
#define now dp[i & 1]
#define pre dp[(i & 1) ^ 1]
inline void init()
{
    memset(ds, 0xf, sizeof ds);
    for (int i = 1; i <= n; i++)
        lg[1 << (i - 1)] = i;
    for (int i = 1; i <= n; i++)
        for (int s = 1; s < tot; s++)
            ds[i][s] = min(ds[i][s - (s & -s)], v[i][lg[s & -s]]);
    for (int s = 1; s < tot; s++)
    {
        int t = (tot - 1) ^ s;
        for (int u = t; u; u = (u - 1) & t)
            dis[s][u] = ds[lg[s & -s]][u] + dis[s - (s & -s)][u];
    }
    vld[0] = 1;
    for (int i = 1; i <= n; i++)
        vld[i << (i - 1)] = 1;
    for (int s = 1; s < tot; s++)
        for (int _s = s; _s; _s ^= _s & -_s)
        {
            int i = lg[_s & -_s];
            if (ds[i][s ^ (_s & -_s)] < 1e7)
                vld[s] = 1;
        }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(v, 0xf, sizeof v);
    for (int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, v[x][y] = v[y][x] = min(v[x][y], z);
    tot = 1 << n;
    init();
    memset(dp, 0xf, sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[0][1 << (i - 1)] = 0;
    int i = 1;
    for (; i < n; i++)
        for (int s = 0; s < tot; s++)
        {
            now[s] = pre[s];
            for (int t = s; t; t = (t - 1) & s)
            {
                int r = s ^ t;
                if (dis[t][r] > 1e8)
                    continue;
                now[s] = min(now[s], pre[r] + i * dis[t][r]);
            }
        }
    int ans = 1e9;
    for (int s = 0; s < tot; s++)
        ans = min(ans, pre[tot - 1]);
    cout << ans << endl;
    return 0;
}