#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2050;
const int MOD = 998244353;
int n, m, tot = 1, ans;
int a[N][N], f[105][205], sum[N][N];

signed main()
{
    // freopen("meal.in","r",stdin);
    // freopen("meal.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int q = 0;
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j] %= MOD, q = (q + a[i][j]) % MOD;
        tot = tot * (q + 1) % MOD;
        for (int j = 1; j <= m; j++)
            sum[i][j] = (q - a[i][j] + MOD) % MOD;
    }
    tot -= 1;
    for (int k = 1; k <= m; k++)
    {
        memset(f, 0, sizeof(f));
        f[0][n] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = n - i; j <= n + i; j++)
            {
                f[i][j] = f[i - 1][j];
                f[i][j] = (f[i][j] + f[i - 1][j - 1] * a[i][k]) % MOD;
                f[i][j] = (f[i][j] + sum[i][k] * f[i - 1][j + 1]) % MOD;
            }
        }
        for (int i = n + 1; i <= n * 2; i++)
            ans = (ans + f[n][i]) % MOD;
    }
    cout << (tot - ans + MOD) % MOD;
    return 0;
}