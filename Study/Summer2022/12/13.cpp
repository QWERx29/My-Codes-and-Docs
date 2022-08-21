#include <bits/stdc++.h>
using namespace std;
const int N = 3100005;
const int INF = 0x3f3f3f3f;
int n, m, s, t, siz, cnt;
int id[110][30005], hd[N], dis[N], vis[N];
struct edge
{
    int nx, to, val;
} e[18000005];
inline void adde(int u, int v, int w) { e[++cnt] = {hd[u], v, w}, hd[u] = cnt; }
inline void init()
{
    for (int i = 1; i <= siz; i++)
        for (int j = 0; j < n; j++)
            id[i][j] = i * n + j;
    for (int i = 1; i <= siz; ++i)
        for (int j = 0; j < n; ++j)
        {
            adde(id[i][j], j, 0);
            if (i + j >= n)
                break;
            adde(id[i][j], id[i][j + i], 1);
            adde(id[i][j + i], id[i][j], 1);
        }
}
queue<int> q;
inline void SPFA()
{
    memset(dis, INF, sizeof dis);
    dis[s] = 0, q.push(s), vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int i = hd[u]; i; i = e[i].nx)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].val)
            {
                dis[v] = dis[u] + e[i].val;
                if (!vis[v])
                    vis[v] = 1, q.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m, siz = sqrt(n / 3);
    init();
    for (int i = 0, b, p; i < m; i++)
    {
        cin >> b >> p;
        if (i == 0)
            s = b;
        if (i == 1)
            t = b;
        if (p <= siz)
            adde(b, id[p][b], 0);
        else
        {
            for (int j = 1; b + j * p < n; j++)
                adde(b, b + j * p, j);
            for (int j = 1; b - j * p >= 0; j++)
                adde(b, b - j * p, j);
        }
    }
    for (int i = 1; i <= siz; i++)
        for (int j = 0; j < n; j++)
            if (hd[id[i][j]])
                adde(id[i][j], j, 0);
    SPFA();
    cout << (dis[t] == INF ? -1 : dis[t]) << '\n';
    return 0;
}