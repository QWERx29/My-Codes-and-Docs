#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

int n, mod, k;

struct mat
{
    ll a[3][3];
    inline mat(int op = 0)
    {
        memset(a, 0, sizeof(a));
        if (op)
            for (int i = 0; i < 3; ++i)
                a[i][i] = 1;
    }
    inline const ll *operator[](int x) const { return a[x]; }
    inline ll *operator[](int x) { return a[x]; }
    inline mat operator*(const mat &b) const
    {
        mat c;
        for (int i = 0; i < 3; i++)
            for (int k = 0; k < 3; k++)
            {
                ll tmp = a[i][k];
                for (int j = 0; j < 3; j++)
                    c[i][j] = (c[i][j] % mod + ((a[i][k] % mod) * (b[k][j] % mod)) % mod) % mod;
            }
        return c;
    }
} s, t, k0(1);

inline mat qkpow1(mat a, ll q)
{
    if (q == 0)
        return k0;
    mat res = qkpow1(a, q / 2);
    res = res * res;
    if (q % 2 == 1)
        res = res * a;
    return res;
}
inline ll qkpow2(ll a, ll q)
{
    if (q == 0)
        return 1;
    ll tmp = qkpow2(a, q / 2);
    tmp = tmp * tmp;
    if (q % 2 == 1)
        tmp = tmp * a;
    return tmp;
}
inline void init()
{
    s.a[0][0] = s.a[0][1] = s.a[0][2] = 1;
    k = 1;
}

signed main()
{
    cin >> n >> mod;
    init();
    for (int i = 1; i <= (int)log10(n); i++)
    {
        t = mat(0);
        ll tmp = qkpow2(10, i);
        t.a[0][0] = tmp % mod;
        t.a[1][0] = t.a[2][0] = t.a[1][1] = t.a[2][1] = t.a[2][2] = 1;
        s = s * qkpow1(t, tmp - 1 - k);
        k = tmp - 1;
    }
    if (k != n)
    {
        t = mat(0);
        ll tmp = qkpow2(10, (int)log10(n) + 1);
        t.a[0][0] = tmp % mod;
        t.a[1][0] = t.a[2][0] = t.a[1][1] = t.a[2][1] = t.a[2][2] = 1;
        s = s * qkpow1(t, n - k);
    }
    cout << (s.a[0][0] + mod) % mod;
    return 0;
}