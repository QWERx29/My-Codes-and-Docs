#include <bits/stdc++.h>
#define ll long long
template <class T>
inline void read(T &x)
{
    x = 0;
    register char c = getchar(), d = 0;
    while (c < '0' || c > '9')
        d = c, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + c - '0', c = getchar();
    if (d == '-')
        x = -x;
}
template <class T>
inline void wt(T x)
{
    if (x / 10)
        wt(x / 10);
    putchar(x % 10 + '0');
}
template <class T>
inline void wtln(T x)
{
    if (x < 0)
        x = -x, putchar('-');
    wt(x), putchar('\n');
}

const int N = 4e7 + 10;
const int MOD = (1 << 30);
int n, type, a[N], t[N];
ll s[N];
int q[N], hd, tl;
__int128 ans;

inline void input()
{
    read(n), read(type);
    if (type == 0)
    {
        for (int i = 1; i <= n; i++)
            read(a[i]);
    }
    else
    {
        ll x, y, z, m;
        int p = 0, q, l, r;
        int b1, b2, b3;
        read(x), read(y), read(z);
        read(b1), read(b2), read(m);
        while (m--)
        {
            q = p;
            read(p), read(l), read(r);
            while (q < p)
            {
                a[++q] = b1 % (r - l + 1) + l;
                b3 = (x * b2 + y * b1 + z) % MOD;
                b1 = b2, b2 = b3;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
}

inline ll g(int i)
{
    return s[i] - s[t[i]];
}
inline ll f(int i)
{
    return s[i] + g(i);
}
inline void work()
{
    hd = tl = 1;
    for (int i = 1; i <= n; i++)
    {
        while (hd <= tl && f(q[hd]) <= s[i])
            ++hd;
        t[i] = q[hd - 1];
        while (hd <= tl && f(q[tl]) >= f(i))
            --tl;
        q[++tl] = i;
    }
}

signed main()
{
    // freopen("partition.in", "r", stdin);
    // freopen("partition.out", "w", stdout);
    input();
    work();
    for (int i = n; i; i = t[i])
    {
        __int128 tmp = s[i] - s[t[i]];
        ans += tmp * tmp;
    }
    wtln(ans);
    return 0;
}