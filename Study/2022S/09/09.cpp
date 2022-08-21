#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
int n, a[N], ans = -0x3f3f3f3f;
char s[N];
int f[N][N], g[N][N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(f, 0xc0, sizeof f), memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i - 1] >> a[i], a[i + n] = a[i];
        if (i - 1 == 0)
            s[n] = s[2 * n] = s[i - 1];
        else
            s[i - 1 + n] = s[i - 1];
        f[i][i] = f[i + n][i + n] = g[i][i] = g[i + n][i + n] = a[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= (n << 1); l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                if (s[k] == 't')
                {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r]);
                }
                if (s[k] == 'x')
                {
                    f[l][r] = max(f[l][r], f[l][k] * f[k + 1][r]);
                    f[l][r] = max(f[l][r], f[l][k] * g[k + 1][r]);
                    f[l][r] = max(f[l][r], g[l][k] * f[k + 1][r]);
                    f[l][r] = max(f[l][r], g[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], g[l][k] * f[k + 1][r]);
                    g[l][r] = min(g[l][r], f[l][k] * g[k + 1][r]);
                    g[l][r] = min(g[l][r], f[l][k] * f[k + 1][r]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1]);
    cout << ans << '\n';
    return 0;
}