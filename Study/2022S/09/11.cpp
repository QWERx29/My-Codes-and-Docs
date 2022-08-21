#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, f[N][N], g[N][N];
char s[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> (s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; i + j + j - 1 <= n; j++)
            g[i][j] = !strncmp(s + i, s + i + j, j);
    for (int i = n; i; i--)
        for (int j = 1; i + j + j - 1 <= n; j++)
            if (g[i][j])
                g[i][j] = g[i + j][j] + 1;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            for (int k = i; k <= j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            for (int k = i, l = 1; k <= j; k++, l++)
                if (!(len % l) && (g[i][l] + 1) >= len / l)
                    f[i][j] = min(f[i][j], f[i][k] + 3 + (len / l > 9));
        }
    }

    cout << f[1][n] << '\n';
    return 0;
}