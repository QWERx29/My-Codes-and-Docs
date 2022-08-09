#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 600;

int f[N][N];
int len = 1, n, p;

inline void catlan(int u)
{
    for (int i = 1; i <= len; i++)
        f[u][i] = f[u - 1][i] + f[u][i];
    for (int i = 1; i <= len; i++)
    {
        f[u][i + 1] += f[u][i] / 10;
        f[u][i] %= 10;
    }
    if (f[u][len + 1])
        len++;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    f[1][1] = 1;
    for (int i = 2; i <= n + 1; i++)
        for (int j = 1; j <= i; j++)
            catlan(j);
    for (int i = len; i > 0; i--)
        cout << f[n][i];
    return 0;
}