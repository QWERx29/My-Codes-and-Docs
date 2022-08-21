#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 3e5 + 30;
int n, m1, m2, s;
int tot, cnt, hd[N], dis[N], vis[N];
int bel[N], in[N];
struct edge
{
    int nx, to, val;
} e[N];
inline void adde(int u, int v, int w) { e[++cnt] = {hd[u], v, w}, hd[u] = cnt; }
vector<int> a[N];
inline void dfs(int u)
{
    vis[u] = 1, bel[u] = tot;
    a[tot].push_back(u);
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (vis[v])
            continue;
        dfs(v);
    }
}
priority_queue<pii, vector<pii>, greater<pii>> q;
queue<int> p;
inline void dijkstra()
{
    memset(vis, 0, sizeof vis), memset(dis, 0x3f, sizeof dis);
    dis[s] = 0, p.push(bel[s]);
    for (int i = 1; i <= tot; i++)
        if (!in[i])
            p.push(i);
    while (!p.empty())
    {
        int pos = p.front();
        p.pop();
        for (auto u : a[pos])
            q.push({dis[u], u});
        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (int i = hd[u]; i; i = e[i].nx)
            {
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].val)
                {
                    dis[v] = dis[u] + e[i].val;
                    if (bel[u] == bel[v])
                        q.push({dis[v], v});
                }
                --in[bel[v]];
                if (bel[v] != bel[u] && !in[bel[v]])
                    p.push(bel[v]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m1 >> m2 >> s;
    for (int i = 1, x, y, z; i <= m1; i++)
        cin >> x >> y >> z, adde(x, y, z), adde(y, x, z);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            tot++, dfs(i);
    for (int i = 1, x, y, z; i <= m2; i++)
        cin >> x >> y >> z, adde(x, y, z), in[bel[y]]++;
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] >= 1000001)
            cout << "NO PATH" << endl;
        else
            cout << dis[i] << endl;
    }
    return 0;
}