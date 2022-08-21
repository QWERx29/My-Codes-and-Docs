#include <bits/stdc++.h>
using namespace std;
const int N = 10086;
const int M = 1005;
const int INF = 0x3f3f3f3f;
int n, m, k, X[N], Y[N], L[N], H[N];
int f[2][M + N], ans = INF, cnt;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> X[i] >> Y[i];
    for (int i = 1, x, y, z; i <= k; i++)
        cin >> x >> y >> z, L[x] = y, H[x] = z;
    for (int i = 1; i <= n; i++)
        if (!L[i] && !H[i])
            L[i] = 0, H[i] = m + 1;
    f[0][0] = INF;
    for (int i = 1; i <= n; i++)
    {
        int _i = i % 2;
        for (int h = 0; h <= m; h++)
            f[_i][h] = INF;
        for (int h = 0; h <= m; h++)
            if (h - X[i] >= 0)
                f[_i][h] = min(INF, min(f[_i ^ 1][h - X[i]], f[_i][h - X[i]]) + 1);
        if (H[i] == m + 1)
            for (int s = 0; s <= X[i]; s++)
                if (m - s)
                    f[_i][m] = min(f[_i][m], min(f[_i ^ 1][m - s], f[_i][m - s]) + 1);
        for (int h = 0; h <= L[i]; h++)
            f[_i][h] = INF;
        for (int h = H[i]; h <= m; h++)
            f[_i][h] = INF;
        for (int h = L[i] + 1; h < H[i]; h++)
            if (h + Y[i] <= m)
                f[_i][h] = min(f[_i][h], f[_i ^ 1][h + Y[i]]);
        for (int h = L[i] + 1; h < H[i]; h++)
        {
            if (f[_i][h] != INF)
                break;
            if (h == H[i] - 1)
                cout << 0 << '\n'
                     << cnt << endl,
                    exit(0);
        }
        if (L[i] || H[i] != m + 1)
            cnt++;
    }
    cout << 1 << '\n';
    for (int h = L[n] + 1; h < H[n]; h++)
        ans = min(ans, f[n % 2][h]);
    cout << ans << '\n';
    return 0;
}