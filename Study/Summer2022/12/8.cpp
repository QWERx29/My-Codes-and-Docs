#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 50;
const int MOD = 100003;
int n, m;
int x, y, cnt, f[N], hd[N], ans[N], dis[N];
struct edge
{
    int nx, to;
} e[N];
void adde(int u, int v)
{
    e[++cnt].nx = hd[u];
    e[cnt].to = v, hd[u] = cnt;
}

inline void spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        dis[i] = 1145141919810;
    dis[1] = 0;
    q.push(1), f[1] = 1, ans[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        f[u] = 0, q.pop();
        for (int i = hd[u]; ~i; i = e[i].nx)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1, ans[v] = ans[u] % MOD;
                if (!f[v])
                    q.push(v), f[v] = 1;
            }
            else if (dis[v] == dis[u] + 1)
                ans[v] += ans[u], ans[v] %= MOD;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(hd, -1, sizeof(hd));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> x >> y, adde(x, y), adde(y, x);
    spfa();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}