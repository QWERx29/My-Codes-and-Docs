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
inline int A(int n, int m) { return mul(fac[n], inf[n - m]); }
inline int C(int n, int m) { return mul(A(n, m), inf[m]); }
inline void init_p()
{
    for (int i = 1; i < N; i++)
        p[i][i] = p[i][1] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 2; j < N; j++)
        {
            if (i >= j)
                p[i][j] = (p[i - 1][j - 1] + p[i - j][j]) % MOD;
            else
                p[i][j] = p[i - 1][j - 1];
        }
    }
}
inline void init_s()
{
    for (int i = 1; i < N; i++)
        s[i][i] = s[i][1] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 2; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + mul(j, s[i - 1][j])) % MOD;
}
// slove
inline int _1(int x, int y) { return qpow(y, x); }
inline int _2(int x, int y) { return C(x - 1, y - 1); }
inline int _3(int x, int y) { return C(x + y - 1, y - 1); }
inline int _4(int x, int y)
{
    init_p();
    return p[x + y][y];
}
inline int _5(int x, int y)
{
    init_p();
    return p[x][y];
}
inline int _6(int x, int y)
{
    init_s();
    return s[x][y];
}
inline int _7(int x, int y)
{
    init_s();
    int res = s[x][y];
    for (int i = 2; i <= y; i++)
        res = mul(res, i);
    return res;
}
inline int _8(int x, int y)
{
    init_s();
    int res = 0;
    for (int i = 1; i <= y; i++)
        res = (res + s[x][i]) % MOD;
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
    /*cout << _1(n, m) << "\n"
         << _2(n, m) << "\n"
         << _3(n, m) << "\n"
         << _4(n, m) << "\n"
         << _5(n, m) << "\n"
         << _6(n, m) << "\n"
         << _7(n, m) << "\n"
         << _8(n, m) << "\n";*/
    cout << _7(n, m) << "\n";
    return 0;
}