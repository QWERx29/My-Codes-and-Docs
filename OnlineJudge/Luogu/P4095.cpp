#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1005;

int n, m, q, pos, ans;
int a[N], b[N], c[N], f[N][N], g[N][N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n, m = 1000;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            f[i][j] = f[i - 1][j];
        int t = c[i];
        for (int k = 1; k <= t; k <<= 1)
        {
            for (int j = m; j >= a[i] * k; j--)
                f[i][j] = max(f[i][j], f[i][j - a[i] * k] + b[i] * k);
            t -= k;
        }
        if (t)
            for (int j = m; j >= a[i] * t; j--)
                f[i][j] = max(f[i][j], f[i][j - a[i] * t] + b[i] * t);
    }
    for (int i = n; i; i--)
    {
        for (int j = 0; j <= m; j++)
            g[i][j] = g[i + 1][j];
        int t = c[i];
        for (int k = 1; k <= t; k <<= 1)
        {
            for (int j = m; j >= a[i] * k; j--)
                g[i][j] = max(g[i][j], g[i][j - a[i] * k] + b[i] * k);
            t -= k;
        }
        if (t)
            for (int j = m; j >= a[i] * t; j--)
                g[i][j] = max(g[i][j], g[i][j - a[i] * t] + b[i] * t);
    }
    cin >> q;
    while (q--)
    {
        cin >> pos >> m, ans = 0;
        pos++;
        for (int i = 0; i <= m; i++)
            ans = max(ans, f[pos - 1][i] + g[pos + 1][m - i]);
        cout << ans << endl;
    }
    return 0;
}