#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 4080;
int n, m, fac[N], inf[N], p[N][N], s[N][N];
inline int mul(int x, int y) { return 1ll * x * y % MOD; }
inline int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
        y & 1 ? (res = mul(res, x)) : 1, x = mul(x, x);
    return res;
}
inline int inv(int x) { return qpow(x, MOD - 2); }
inline void init_s()
{
    for (int i = 1; i < N; i++)
        s[i][i] = s[i][1] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 2; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + mul(j, s[i - 1][j])) % MOD;
}
inline int solve(int x, int y)
{
    init_s();
    int res = s[x][y];
    for (int i = 2; i <= y; i++)
        res = mul(res, i);
    return res;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = mul(fac[i - 1], i);
    inf[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; ~i; i--)
        inf[i] = mul(inf[i + 1], i + 1);
    cout << solve(n, m) << "\n";
    return 0;
}