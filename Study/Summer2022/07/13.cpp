#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int p;
inline ll qpow(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
        b & 1 ? res = res * a % p : 1, a = a * a % p;
    return res;
}
inline ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
map<int, int> hsh;
inline int BSGS(int a, int b)
{
    hsh.clear();
    b %= p;
    int t = ceil(sqrt(p));
    for (int j = 0; j < t; j++)
    {
        int val = 1ll * b * qpow(a, j) % p;
        hsh[val] = j;
    }
    a = qpow(a, t);
    if (!a)
        return !b ? 1 : -1;
    for (int i = 0; i <= t; i++)
    {
        int val = qpow(a, i);
        int j = hsh.find(val) == hsh.end() ? -1 : hsh[val];
        if (j >= 0 && i * t - j >= 0)
            return i * t - j;
    }
    return -1;
}
int t, k, y, z;
ll _x, _y;
// solve
inline void _1() { return cout << qpow(y, z) << '\n', void(); }
inline void _2()
{
    ll g = exgcd(y, p, _x, _y);
    if (z % g)
        return cout << "Orz, I cannot find x!\n", void();
    ll tmp = p / g;
    while (_x < 0)
        _x += tmp;
    cout << ((_x * z / g) % tmp + tmp) % tmp << '\n'; //!
}
inline void _3()
{
    ll ans = BSGS(y, z);
    if (ans == -1)
        cout << "Orz, I cannot find x!\n";
    else
        cout << ans << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t >> k;
    while (t--)
    {
        cin >> y >> z >> p;
        if (k == 1)
            _1();
        else if (k == 2)
            _2();
        else
            _3();
    }
    return 0;
}