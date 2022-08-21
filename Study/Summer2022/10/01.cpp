#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, tot, ans, tmp;
int f[15][250][2000], sz[1050];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    tot = (1 << n) - 1;
    while (tot)
    {
        tmp = tot;
        for (int i = 0; i < n; i++)
            tmp = tot >> i, sz[tot] += tmp & 1;
        tot--;
    }
    tot = (1 << n) - 1;
    for (int i = 0; i <= tot; i++)
        if (!(i & (i << 1)))
            f[0][sz[i]][i] = 1;
    for (int i = 0; i < n - 1; i++)
        for (int s = 0; s <= tot; s++)
            if (!(s & (s << 1)))
                for (int t = 0; t <= tot; t++)
                    if (!(t & (t << 1)))
                        if (!(s & t) && !(s & (t << 1)) && !(s & (t >> 1)))
                            for (int j = 0; j <= k - sz[t]; j++)
                                f[i + 1][j + sz[t]][t] += f[i][j][s];
    for (int i = 0; i <= tot; i++)
        ans += f[n - 1][k][i];
    cout << ans;
    return 0;
}