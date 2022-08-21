#include <bits/stdc++.h>
using namespace std;
const int N = 9.1e6 + 50;
const int INF = 0x7f7f7f7f;
int hd[N], cnt;
int n, m, st, ed, ans;
int dep[N], dis[N], vis[N];
struct edge
{
    int nx, to, val;
} e[N];
inline void adde(int u, int v, int w) { e[++cnt] = {hd[u], v, w}, hd[u] = cnt; }
inline void init()
{
    int tmp, _1, _2;
    for (int i = 1; i < m; i++)
        cin >> tmp, adde(i << 1, ed, tmp);
    for (int i = 2; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            cin >> tmp;
            _1 = (((i - 2) * (m - 1)) << 1) - 1 + (j << 1);
            _2 = (((i - 1) * (m - 1)) << 1) + (j << 1);
            adde(_1, _2, tmp), adde(_2, _1, tmp);
        }
    for (int i = 1; i < m; i++)
    {
        cin >> tmp;
        _1 = (((n - 2) * (m - 1)) << 1) - 1 + (i << 1);
        adde(st, _1, tmp);
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++) //?
        {
            cin >> tmp;
            _1 = (((i - 1) * (m - 1)) << 1) + (j << 1) - 1;
            _2 = _1 - 1;
            if (j == 1)
                adde(st, _1, tmp);
            else if (j == m)
                adde(_2, ed, tmp);
            else
                adde(_1, _2, tmp), adde(_2, _1, tmp);
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            cin >> tmp;
            _1 = (((i - 1) * (m - 1)) << 1) + (j << 1) - 1;
            _2 = _1 + 1;
            adde(_1, _2, tmp), adde(_2, _1, tmp);
        }
}
struct node
{
    int id, val;
    node() {}
    node(int _id, int _val) { id = _id, val = _val; }
    inline bool operator<(const node &o) const { return val > o.val; }
};
priority_queue<node> q;
inline void dijkstra(int s)
{
    memset(dis, INF, sizeof dis);
    dis[s] = 0, q.push(node(s, 0));
    while (!q.empty())
    {
        int u = q.top().id;
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
                if (!vis[v])
                    q.push(node(v, dis[v]));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ed = ((n << 1) - 2) * (m - 1) + 1;
    init();
    dijkstra(0);
    cout << dis[ed] << '\n';
    return 0;
}