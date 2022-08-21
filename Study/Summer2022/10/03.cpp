#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt;
int r[110], sz[1100], st[65], f[110][65][65];
char str[12];
int S, T, U;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            r[i] |= (str[j] == 'H') << j;
    }
    for (int i = 0; i < (1 << m); i++)
    {
        sz[i] = sz[i >> 1] + (i & 1);
        if ((i & (i >> 1)) || (i & (i >> 2)))
            continue;
        st[++cnt] = i, f[0][1][cnt] = sz[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            S = st[j];
            if (S & r[i])
                continue;
            for (int k = 1; k <= cnt; k++)
            {
                T = st[k];
                if ((S & T) || (T & r[i + 1]))
                    continue;
                for (int l = 1; l <= cnt; l++)
                {
                    U = st[l];
                    if ((S & U) || (T & U) || (U & r[i + 2]))
                        continue;
                    f[i + 1][k][l] = max(f[i + 1][k][l], f[i][j][k] + sz[st[l]]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= cnt; j++)
            ans = max(ans, f[n - 1][i][j]);
    }
    cout << ans;
    return 0;
}