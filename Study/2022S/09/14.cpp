#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2022;

struct edge
{
    int to, nt;
} a[N << 1];
int h[N], vis[N], f[N][3], c[N];
int n, cnt, rt;
inline void adde(int x, int y)
{
    cnt++;
    a[cnt].to = y, a[cnt].nt = h[x], h[x] = cnt;
}
inline void dp(int x, int fa)
{
    int d = 1145141919810;
    for (int i = h[x]; i; i = a[i].nt)
    {
        int y = a[i].to;
        if (y == fa)
            continue;
        dp(y, x);
        int t = min(f[y][1], f[y][2]);
        f[x][0] += t, f[x][1] += t;
        d = min(d, f[y][2] - t);
        f[x][2] += min(t, f[y][0]);
    }
    f[x][1] += d, f[x][2] += c[x];
}

signed main()
{
    int x, y, t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cin >> c[x] >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> y;
            adde(x, y);
            vis[y] = 1;
        }
    }
    rt = 1;
    while (vis[rt])
        rt++;
    dp(rt, 0);
    cout << min(f[rt][1], f[rt][2]) << endl;
    return 0;
}