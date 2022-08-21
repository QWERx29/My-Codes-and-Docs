#include <bits/stdc++.h>
using namespace std;
const int N = 2022;
const int MOD = (1 << 31) - 1;
const int INF = 0x3f3f3f3f;
int n, m, ans;
int dis[N], c[N][N], vis[N];
long long sum = 1;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            c[i][j] = dis[j] = INF;
    cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, c[x][y] = c[y][x] = z;
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (k == 0 || dis[j] <= dis[k]))
                k = j;
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
            if (!vis[j])
                dis[j] = min(dis[j], dis[k] + c[k][j]);
    }
    for (int i = 2; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= n; j++)
            if (dis[i] == dis[j] + c[j][i] && dis[i] != INF)
                ans++;
        sum = sum * ans % MOD;
    }
    cout << sum << "\n";
    return 0;
}