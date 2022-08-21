#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2335;
const int MOD = 2333;
ll c[N][N], f[N][N];
ll n, k;
inline ll lucas(ll n, ll m)
{
    if (!m || n == m)
        return 1;
    if (n < m)
        return 0;
    return c[n % MOD][m % MOD] * lucas(n / MOD, m / MOD) % MOD;
}
inline ll F(ll n, ll k)
{
    if (k < 0)
        return 0;
    if (!n || !k)
        return 1;
    if (n < MOD && k < MOD)
        return f[n][k];
    return (F(n / MOD, k / MOD - 1) * f[n % MOD][MOD - 1] % MOD + lucas(n / MOD, k / MOD) * f[n % MOD][k % MOD] % MOD) % MOD;
}
inline void init()
{
    c[0][0] = 1;
    for (int i = 1; i < N; i++)
        c[i][i] = c[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    f[0][0] = 1;
    for (int i = 1; i < N; i++)
        f[i][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            f[i][j] = (c[i][j] + f[i][j - 1]) % MOD;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cout << F(n, k) << endl;
    }
    return 0;
}