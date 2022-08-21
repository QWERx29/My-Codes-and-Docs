#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, x, y;
inline ll exgcd(ll a, ll b)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        int res = exgcd(b, a % b), _x = x, _y = y;
        x = _y, y = _x - a / b * _y;
        return res;
    }
}
int main()
{
    ll n, m, l;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> x >> y >> m >> n >> l;
    a = x - y, b = n - m;
    if (b < 0)
        b = -b, a = -a;
    ll k = exgcd(b, l);
    if (a % k != 0)
        cout << "Impossible\n";
    else
        cout << ((x * (a / k)) % (l / k) + (l / k)) % (l / k) << "\n";
    return 0;
}
