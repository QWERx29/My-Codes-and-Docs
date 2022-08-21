#include <bits/stdc++.h>
using namespace std;
const int N = 11451;
struct edge
{
    int nx, to, val;
} e[N << 1];
int hd[N], dis[N], vis[N];
int n, cnt;
inline int SPFA(int pre)
{
    queue<int> q;
    memset(dis, 0x3f, sizeof dis), memset(vis, 0, sizeof vis);
    dis[pre] = 0, vis[pre] = 1;
    q.push(pre);
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
    int r = pre;
    for (int i = 1; i <= n; i++)
        if (dis[i] != dis[0] && dis[i] > dis[r])
            r = i;
    return r;
}
inline void adde(int u, int v, int w)
{
    e[++cnt] = {hd[u], v, w};
    hd[u] = cnt;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, x, y, z; i < n; i++)
        cin >> x >> y >> z, adde(x, y, z), adde(y, x, z);
    cout << dis[SPFA(SPFA(1))] << '\n';
    return 0;
}