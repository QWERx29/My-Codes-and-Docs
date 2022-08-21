#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1145141;
const int INF = 0x3f3f3f3f;
int n, m, x_1, x_2, y_1, y_2, ans;
int cnt_1, cnt_2, hd_1[N], hd_2[N], in[N], vis[N], dis[5][N], dist[N];
struct edge
{
    int nx, to, val;
} e_1[N], e_2[N];
inline void adde_1(int u, int v, int w) { e_1[++cnt_1] = {hd_1[u], v, w}, hd_1[u] = cnt_1; }
inline void adde_2(int u, int v, int w) { e_2[++cnt_2] = {hd_2[u], v, w}, hd_2[u] = cnt_2, in[v]++; }
priority_queue<pii, vector<pii>, greater<pii>> pq;
inline void dijsktra(int id, int x)
{
    memset(dis[id], INF, sizeof dis[id]);
    memset(vis, 0, sizeof vis);
    dis[id][x] = 0, pq.push({dis[id][x], x});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = hd_1[u]; i; i = e_1[i].nx)
        {
            int v = e_1[i].to;
            if (dis[id][v] > dis[id][u] + e_1[i].val)
            {
                dis[id][v] = dis[id][u] + e_1[i].val;
                if (!vis[v])
                    pq.push({dis[id][v], v});
            }
        }
    }
}
queue<int> q;
inline void topo()
{
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = hd_2[u]; i; i = e_2[i].nx)
        {
            int v = e_2[i].to;
            in[v]--;
            dist[v] = max(dist[v], dist[u] + e_2[i].val);
            if (!in[v])
                q.push(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    for (int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, adde_1(x, y, z), adde_1(y, x, z);
    dijsktra(1, x_1), dijsktra(2, y_1), dijsktra(3, x_2), dijsktra(4, y_2);
    for (int u = 1; u <= n; u++)
        for (int i = hd_1[u]; i; i = e_1[i].nx)
        {
            int v = e_1[i].to;
            if (dis[1][u] + e_1[i].val + dis[2][v] == dis[1][y_1])
                if (dis[3][u] + e_1[i].val + dis[4][v] == dis[3][y_2])
                    adde_2(u, v, e_1[i].val);
        }
    topo();
    for (int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);
    memset(hd_2, 0, sizeof hd_2), cnt_2 = 0, memset(in, 0, sizeof in), memset(dist, 0, sizeof dist);
    for (int u = 1; u <= n; u++)
        for (int i = hd_1[u]; i; i = e_1[i].nx)
        {
            int v = e_1[i].to;
            if (dis[1][u] + e_1[i].val + dis[2][v] == dis[1][y_1])
                if (dis[4][u] + e_1[i].val + dis[3][v] == dis[3][y_2])
                    adde_2(u, v, e_1[i].val);
        }
    topo();
    for (int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);
    cout << ans << '\n';
    return 0;
}