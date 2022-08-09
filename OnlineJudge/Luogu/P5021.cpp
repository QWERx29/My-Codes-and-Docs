#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
using namespace std;
const int N = 114514;
struct edge
{
    int nx, to, val;
} e[N];
int ans, cnt, hd[N];
inline void adde(int u, int v, int w)
{
    e[++cnt].nx = hd[u];
    e[cnt].to = v, e[cnt].val = w;
    hd[u] = cnt;
}
int l, r, mid, m, n, tot;
inline int dfs(int u, int pre = 0)
{
    multiset<int> s;
    multiset<int>::iterator it;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == pre)
            continue;
        int dis = dfs(v, u) + e[i].val;
        if (dis >= mid)
            tot++;
        else
            s.insert(dis);
    }
    int res = 0;
    while (!s.empty())
    {
        int dis = *s.begin();
        s.erase(s.begin());
        it = s.lower_bound(mid - dis);
        if (it == s.end())
            res = dis;
        else
            ++tot, s.erase(it);
    }
    return res;
}
inline bool check()
{
    tot = 0;
    dfs(1);
    if (tot >= m)
        return 1;
    else
        return 0;
}
signed main()
{
    // IO("track");
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int a, b, w;
    for (int i = 1; i < n; i++)
        cin >> a >> b >> w, adde(a, b, w), adde(b, a, w), r += w;
    r /= m;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check())
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
