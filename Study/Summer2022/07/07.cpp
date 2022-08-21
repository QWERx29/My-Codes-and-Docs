#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e6 + 10;
const int MOD = 9901;
int a, b;
int pri[N], cnt[N], tot;
inline int mod(int x, int p = MOD) { return (x % p + p) % p; }
inline int mul(ll x, int y, int p = MOD) { return x * y % p; }
inline int qpow(ll a, int b)
{
    if (a == 0)
        return 0;
    b = mod(b, MOD - 1); //?
    int r = 1;
    for (; b; b >>= 1)
        b & 1 ? r = mul(r, a) : 1, a = mul(a, a);
    return r;
}
int ans = 1;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    if (a == 0)
        cout << 0 << "\n", exit(0);
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            pri[++tot] = i;
            while (a % i == 0)
                a /= i, cnt[tot]++;
        }
    }
    if (a > 1)
        pri[++tot] = a, cnt[tot] = 1;
    for (int i = 1; i <= tot; i++)
    {
        ans = mul(ans, qpow(pri[i], mul(b, cnt[i], MOD - 1) + 1) - 1); //?
        ans = mul(ans, qpow(pri[i] - 1, MOD - 2));
    }
    cout << ans << "\n";
    return 0;
}
