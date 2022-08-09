#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

int b[15], c[15], sum[15], mod, ansm, ansk, n, k, m;

struct mat
{
    ll a[16][16];
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
        for (int i = 0; i <= n; i++)
            for (int k = 0; k <= n; k++)
            {
                ll tmp = a[i][k];
                for (int j = 0; j <= n; j++)
                    c[i][j] = (c[i][j] + tmp * b[k][j]) % mod;
            }
        return c;
    }
} s, t;

inline void init()
{
    for (int i = 0; i < n; i++)
        s.a[0][i] = b[i];
    s.a[0][n] = sum[n - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            s.a[i][j] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == j + 1)
                t.a[i][j] = 1;
            else
                t.a[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
        t.a[i][n - 1] = t.a[i][n] = c[n - i - 1];
    t.a[n][n - 1] = 0, t[n][n] = 1;
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i], sum[i] = b[i] + sum[i - 1];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    cin >> m >> k >> mod;
    m -= n + 1;
    k -= n;
    if (m <= 0)
        ansm = sum[m + n - 1];
    else
    {
        init();
        while (m)
        {
            if (m & 1)
                s = s * t;
            t = t * t;
            m >>= 1;
        }
        ansm = s.a[0][n];
    }
    if (k <= 0)
        ansk = sum[k + n - 1];
    else
    {
        init();
        while (k)
        {
            if (k & 1)
                s = s * t;
            t = t * t;
            k >>= 1;
        }
        ansk = s.a[0][n];
    }
    cout << (ansk - ansm + mod) % mod;
    return 0;
}