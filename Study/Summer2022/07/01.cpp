#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 50;
const ll INF = 1e18;
int n, tot, cnt;
ll ans[N];
int pri[N], vis[N];
inline void seive()
{
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] < N; j++)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
inline bool isPri(int n)
{
    if (n < N)
        return !vis[n];
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
inline void dfs(int i, int n, ll cur)
{
    if (n == 1)
        return ans[++cnt] = cur, void();
    if (i > tot || pri[i] + 1 > n)
        return;
    if (1ll * pri[i] * pri[i] > n)
    {
        if (isPri(n - 1))
            ans[++cnt] = cur * (n - 1);
        return;
    }
    ll a = 1, sum = 1;
    while (sum <= n)
    {
        if (n % sum == 0)
            dfs(i + 1, n / sum, cur * a);
        a *= pri[i], sum += a;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    seive();
    {
        while (cin >> n)
        {
            cnt = 0;
            dfs(1, n, 1);
            sort(ans + 1, ans + cnt + 1);
            cout << cnt << "\n";
            for (int i = 1; i <= cnt; i++)
                cout << ans[i] << " \n"[i == cnt];
        }
        return 0;
    }
}