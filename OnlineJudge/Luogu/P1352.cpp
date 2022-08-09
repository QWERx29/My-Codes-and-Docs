#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
int n, p[N], x, y;
struct edge
{
    int nt, to;
    inline void init(int t, int n) { to = t, nt = n; }
} e[N << 1];
int c = 1, h[N], dp[N][2];
inline void adde(int x, int y)
{
    e[++c].init(y, h[x]), h[x] = c;
    e[++c].init(x, h[y]), h[y] = c;
}
inline void dfs(int pos, int pnt = 0)
{
    dp[pos][1] = p[pos];
    for (int i = h[pos]; i; i = e[i].nt)
    {
        int tps = e[i].to;
        if (tps == pnt)
            continue;
        dfs(tps, pos);
        dp[pos][0] += max(dp[tps][0], dp[tps][1]);
        dp[pos][1] += dp[tps][0];
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    while (cin >> x >> y)
    {
        if (x == 0 && y == 0)
            break;
        adde(x, y);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}