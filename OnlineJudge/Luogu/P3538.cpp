#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
const int B = 233;
const int MOD = 998244353;
int n, q, a, b;
int pw[N], hs[N], mp[N];
bool vis[N];
char s[N];
inline int mul(int x, int y) { return x * y % MOD; }
inline int inc(int x, int y) { return x + y < MOD ? x + y : x + y - MOD; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + MOD : x - y; }
inline void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        mp[i] = i;
        for (int j = i * i; j <= n; j += i)
        {
            vis[j] = 1;
            if (!mp[j])
                mp[j] = i;
        }
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = mul(pw[i - 1], B);
        hs[i] = inc(mul(hs[i - 1], B), s[i]);
    }
}
inline int hsh(int l, int r) { return dec(hs[r], mul(hs[l - 1], pw[r - l + 1])); }
inline bool chk(int l, int r, int d) { return hsh(l, r - d) == hsh(l + d, r); }
inline int cal(int l, int r)
{
    int ans = r - l + 1;
    for (int i = ans; i != 1; i /= mp[i])
    {
        if (chk(l, r, ans / mp[i]))
            ans /= mp[i];
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> (s + 1) >> q;
    init(n);
    while (q--)
        cin >> a >> b, cout << cal(a, b) << endl;
    return 0;
}