#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 50;
struct edge
{
    int nx, to, val;
} e[N << 2];
int hd[N << 2], cnt;
int n, m, r, c[N];
inline void adde(int u, int v, int w) { e[++cnt] = {hd[u], v, w}, hd[u] = cnt; }
struct node
{
    int pos, dis;
    node() {}
    node(int _p, int _d) { pos = _p, dis = _d; }
    inline bool operator<(const node &o) const { return dis > o.dis; }
};
priority_queue<node> q;
bool vis[N << 2];
int dis[N << 2], st, ed, b;
inline void dijkstra(int t)
{

    dis[st] = 0, q.push(node(st, 0));
    while (!q.empty())
    {
        // int u = q.top().pos;
        node nd = q.top();
        int u = nd.pos;
        if (q.top().dis != dis[u])
        {
            q.pop();
            continue;
        }
        q.pop();
        if (c[u] > t)
            continue;
        for (int i = hd[u]; i; i = e[i].nx)
        {
            int v = e[i].to;
            if (c[v] > t)
                continue;
            if (dis[v] > dis[u] + e[i].val)
            {
                dis[v] = dis[u] + e[i].val;
                q.push(node(v, dis[v]));
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tmp = 0;
    cin >> n >> m >> st >> ed >> b;
    for (int i = 1; i <= n; i++)
        cin >> c[i], tmp = max(tmp, c[i]);
    for (int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, adde(x, y, z), adde(y, x, z);
    int l = 1, r = tmp;
    memset(dis, 0x3f, sizeof dis);
    dijkstra(tmp + 1);
    if (dis[ed] > b)
        cout << "-1\n", exit(0);
    else if (dis[ed] <= b)
    {
        while (l < r)
        {
            memset(dis, 0x3f, sizeof dis);
            int mid = (l + r) >> 1;
            dijkstra(mid);
            if (dis[ed] <= b)
                r = mid;
            else
                l = mid + 1;
        }
    }
    cout << r << "\n";
    return 0;
}
