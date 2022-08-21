#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, k, cnt, ans;
int st[4200], sz[4200], f[20][4200][400];
inline int inc(int &x, int y) { return (x += y) >= MOD ? (x -= MOD) : x; }
inline void dfs(int num, int sum, int pos)
{
    if (pos >= n)
        return st[cnt] = num, sz[cnt] = sum, cnt++, void();
    dfs(num, sum, pos + 1);
    if (sum < k)
        dfs(num + (1 << pos), sum + 1, pos + 2);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    dfs(0, 0, 0);
    for (int i = 0; i < cnt; i++)
        f[1][i][sz[i]] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < cnt; j++)
            for (int t = 0; t < cnt; t++)
                if (!(st[j] & st[t]) && !((st[j] << 1) & st[t]) && !((st[j] >> 1) & st[t]))
                    for (int s = k; s >= sz[t]; s--)
                        f[i][t][s] = inc(f[i][t][s], f[i - 1][j][s - sz[t]]);
    for (int i = 0; i < cnt; i++)
        ans = inc(ans, f[n][i][k]);
    cout << ans;
    return 0;
}