#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans = 1145141919810;
int a[21][21], f[45114][21];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(f, 0x3f, sizeof(f));
    f[1][1] = 0;
    for (int s = 1; s < (1 << n); s++)
        for (int i = 1; i <= n; i++)
            if ((s >> (i - 1)) & 1)
                for (int j = 1; j <= n; j++)
                    if (!((s >> (j - 1)) & 1))
                        f[s | (1 << (j - 1))][j] = min(f[s | (1 << (j - 1))][j], f[s][i] + a[i][j]);
    for (int i = 1; i <= n; i++)
        ans = min(ans, f[(1 << n) - 1][i] + a[i][1]);
    cout << ans;
    return 0;
}