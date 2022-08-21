#include <bits/stdc++.h>
#define int long long
using namespace std;
const int S = 270005;
const double EPS = 1e-6;
int t, n, m, u[20][20], s, dp[S];
double x[20], y[20];
inline int getSet(int x)
{
    return 1 << (x - 1);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(dp, 0x3f, sizeof dp);
        memset(u, 0, sizeof u);
        cin >> n >> m;
        s = (1 << n) - 1, dp[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        for (int i = 1; i <= n; i++)
        {
            u[i][i] += getSet(i);
            double x1 = x[i], y1 = y[i], x2, y2, den, a, b;
            for (int j = 1; j <= n; j++)
            {
                if (x[i] != x[j])
                {
                    x2 = x[j], y2 = y[j], den = x1 * x2 * (x1 - x2);
                    a = (y1 * x2 - x1 * y2) / den, b = (x1 * x1 * y2 - y1 * x2 * x2) / den;
                    if (a < 0)
                    {
                        u[i][j] += getSet(i) + getSet(j);
                        for (int k = 1; k <= n; k++)
                        {
                            if (k != i && k != j && fabs(a * x[k] * x[k] + b * x[k] - y[k]) <= EPS)
                                u[i][j] += getSet(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= s; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    dp[i | u[j][k]] = min(dp[i | u[j][k]], dp[i] + 1);
        cout << dp[s] << endl;
    }
    return 0;
}