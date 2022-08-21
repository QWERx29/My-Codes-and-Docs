#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 50;
int n, mod, ans = 1;
int pri[N / 10], tot, pre[N], cnt[N];
bool v[N];
inline void init()
{
    v[0] = v[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!v[i])
            pri[++tot] = i, pre[i] = i;
        for (int j = 1; j <= tot && pri[j] * i < N; j++)
        {
            int p = pri[j];
            v[i * p] = 1, pre[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
}
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1)
        y & 1 ? (res = 1ll * res * x % mod) : 1, x = 1ll * x * x % mod;
    return res;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    cin >> n >> mod;
    for (int i = 2; i <= n; i++)
        cnt[i] = -1;
    cnt[n + 1] = 0;
    for (int i = n + 2; i <= n * 2; i++)
        cnt[i] = 1;
    for (int i = n * 2; i >= 2; i--)
    {
        if (pre[i] == i)
            continue;
        cnt[pre[i]] += cnt[i], cnt[i / pre[i]] += cnt[i], cnt[i] = 0;
    }
    for (int i = 2; i <= n * 2; i++)
        ans = 1ll * ans * qpow(i, cnt[i]) % mod;
    cout << ans << "\n";
    return 0;
}