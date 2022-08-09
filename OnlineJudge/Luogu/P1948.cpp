#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 50;
const int INF = 0x7fffffff;
int n, m, k, a, b, c, l, r, mid;
int cnt, ans = -1, maxx = -INF, minx = INF;
int hd[N], w[N], dis[N], ex[N];
struct edge
{
    int nx, to, val;
} e[N];
inline void adde(int x, int y, int z)
{
    e[++cnt].nx = hd[x];
    e[cnt].to = y, e[cnt].val = z;
    hd[x] = cnt;
}
inline int spfa()
{
    memset(dis, 0x3f, sizeof dis), memset(ex, 0, sizeof ex);
    queue<int> q;
    q.push(1), dis[1] = 0, ex[1] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        ex[k] = 0;
        for (int i = hd[k]; ~i; i = e[i].nx)
        {
            int j = e[i].to;
            if (dis[j] > dis[k] + w[i])
            {
                dis[j] = dis[k] + w[i];
                if (!ex[j])
                    ex[j] = 1, q.push(j);
            }
        }
    }
    return dis[n];
}
inline int judge(int x)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = hd[i]; ~j; j = e[j].nx)
        {
            if (e[j].val <= x)
                w[j] = 0;
            else
                w[j] = 1;
        }
    }
    int dat = spfa();
    if (dat <= k)
        return 1;
    else
        return 0;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> k;
    memset(hd, -1, sizeof hd);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        adde(a, b, c), adde(b, a, c);
        if (maxx < c)
            maxx = c;
        if (minx > c)
            minx = c;
    }
    l = 0, r = maxx;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (judge(mid))
            ans = mid, r = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}