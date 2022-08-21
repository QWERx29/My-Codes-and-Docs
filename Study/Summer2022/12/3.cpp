#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 114514;
struct edge
{
    int nx, to, val;
    inline bool operator<(const edge &o) const { return val < o.val; }
} e[N];
ll n, m, tot, ans;
ll pnt[N], sz[N], cnt[N];
inline void adde(int u, int v, int w) { e[++tot].nx = u, e[tot].to = v + n, e[tot].val = w; }
inline int getpnt(int x) { return x == pnt[x] ? x : pnt[x] = getpnt(pnt[x]); }
inline void mrg(int x, int y) { pnt[x] = y, sz[y] += sz[x], cnt[y] += cnt[x] + 1; }
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1, x; j <= m; j++)
            cin >> x, adde(i, j, x);
    sort(e + 1, e + tot + 1);
    for (int i = 1; i <= n + m; i++)
        pnt[i] = i, sz[i] = 1;
    for (int i = 1; i <= m * n; i++)
    {
        int x = getpnt(e[i].nx), y = getpnt(e[i].to);
        if (x != y && cnt[x] + cnt[y] + 1 <= sz[x] + sz[y])
            ans += e[i].val, mrg(x, y);
        else if (cnt[x] < sz[x])
            ans += e[i].val, cnt[x]++;
    }
    cout << ans << '\n';
    return 0;
}