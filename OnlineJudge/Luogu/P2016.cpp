#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int f[N][2], hd[N], cnt, n;
struct edge
{
    int nx, to;
} e[N];
inline void adde(int u, int v) { e[++cnt] = {hd[u], v}, hd[u] = cnt; }
inline void dp(int u, int pre)
{
    f[u][0] = 0, f[u][1] = 1;
    for (int i = hd[u]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if (v == pre)
            continue;
        dp(v, u);
        f[u][1] += min(f[v][0], f[v][1]);
        f[u][0] += f[v][1];
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        for (int j = 1, z; j <= y; j++)
            cin >> z, adde(x, z), adde(z, x);
    }
    dp(0, -1);
    cout << min(f[0][0], f[0][1]) << '\n';
    return 0;
}