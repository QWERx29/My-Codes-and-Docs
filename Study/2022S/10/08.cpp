#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 50;
int n, m, ans;
int f[N][40], num[N][40];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, a, b, c, t; i <= m; i++)
    {
        int ak = 0, fr = 0;
        cin >> a >> b >> c;
        for (int j = 1; j <= b; j++)
        {
            cin >> t;
            t = (t - a + n) % n;
            fr |= (1 << t);
        }
        for (int j = 1; j <= c; j++)
        {
            cin >> t;
            t = (t - a + n) % n;
            ak |= (1 << t);
        }
        for (int j = 0; j < 32; j++)
            if (j & fr || ~j & ak)
                ++num[a][j];
    }
    for (int i = 0; i < 32; i++)
    {
        memset(f[0], 128, sizeof f[0]);
        f[0][i] = 0;
        for (int j = 1; j <= n; j++)
            for (int s = 0; s < 32; s++)
                f[j][s] = max(f[j - 1][(s & 15) << 1], f[j - 1][(s & 15) << 1 | 1]) + num[j][s];
        ans = max(ans, f[n][i]);
    }
    cout << ans << '\n';
    return 0;
}
