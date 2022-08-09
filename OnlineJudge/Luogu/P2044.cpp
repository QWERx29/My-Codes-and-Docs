#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
// const int N=50;

int k, mod, n = 2, a, c, x0, g;

inline ll slow_mul(ll x, ll y)
{
    ll res = 0;
    while (y)
    {
        if (y & 1)
            res = (res + x) % mod;
        x = (x << 1) % mod, y >>= 1;
    }
    return res;
}

struct mat
{
    ll a[2][2];
    inline mat(int op = 0)
    {
        memset(a, 0, sizeof(a));
        if (op)
            for (int i = 0; i < n; ++i)
                a[i][i] = 1;
    }
    inline const ll *operator[](int x) const { return a[x]; }
    inline ll *operator[](int x) { return a[x]; }
    inline mat operator*(const mat &b) const
    {
        mat c;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
            {
                ll tmp = a[i][k];
                for (int j = 0; j < n; j++)
                    c[i][j] = (c[i][j] + slow_mul(tmp, b[k][j])) % mod;
            }
        return c;
    }
} s, t;

inline mat qpow(mat x, int y)
{
    mat res(1);
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
    }
    return res;
}
inline void init()
{
    s.a[0][0] = x0, s.a[0][1] = 1;
    t.a[0][0] = a, t.a[1][0] = c, t.a[0][1] = 0, t.a[1][1] = 1;
}

signed main()
{
    cin >> mod >> a >> c >> x0 >> k >> g;
    init();
    mat res = s * qpow(t, k);
    cout << res.a[0][0] % g;
    return 0;
}