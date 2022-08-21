#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 20;
const int MOD = 1e8 + 7;
int n, X[N], Y[N], a[N][N], f[N][1 << N], ans;
bool vis[N][1 << N];
queue<pii> q;
inline bool is_sgt(int x)
{
    int cnt = 0;
    for (; x; x -= (x & (-x)))
        cnt++;
    return cnt >= 4;
}
inline bool is_on(int x, int s, int t)
{
    if (X[x] < min(X[s], X[t]) || X[x] > max(X[s], X[t]) || Y[x] < min(Y[s], Y[t]) || Y[x] > max(Y[s], Y[t]))
        return 0;
    return ((X[x] - X[s]) * (Y[t] - Y[x]) - (X[t] - X[x]) * (Y[x] - Y[s]) == 0);
}
inline bool chk(int x, int s, int t) { return ((a[s][t] & x) == a[s][t]); }
inline void inc(int &x, int y) { x += y, x >= MOD ? x -= MOD : 1; }
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> X[i] >> Y[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                for (int k = 1; k <= n; k++)
                    if (k != i && k != j && is_on(k, i, j))
                        a[i][j] += (1 << k);
    for (int i = 1; i <= n; i++)
        vis[i][1 << i] = 1, f[i][1 << i] = 1, q.push({i, (1 << i)});
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (is_sgt(y))
            inc(ans, f[x][y]);
        for (int i = 1, j = 2; i <= n; i++, j <<= 1)
        {
            if (!(j & y))
            {
                if (!chk(y, x, i))
                    continue;
                if (!vis[i][j | y])
                    vis[i][j | y] = 1, q.push({i, j | y});
                inc(f[i][j | y], f[x][y]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}