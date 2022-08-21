#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3080;

int n, m, x;
int a[N], sz[N], tmp[N], f[N][N];
vector<int> e[N];
inline void adde(int x, int y)
{
    e[x].push_back(y);
}
inline void dfs(int u)
{
    sz[u] = 1, f[u][1] = a[u];
    for (int v : e[u])
    {
        dfs(v);
        for (int i = 1; i <= sz[u]; i++)
            tmp[i] = f[u][i];
        for (int i = 1; i <= sz[u]; i++)
            for (int j = 1; j <= sz[v]; j++)
                f[u][i + j] = max(f[u][j + i], tmp[i] + f[v][j]);
        sz[u] += sz[v];
    }
}

signed main()
{
    cin >> n >> m;
    m++;
    for (int i = 1; i <= n; i++)
        cin >> x >> a[i], adde(x, i);
    dfs(0);
    cout << f[0][m] << endl;
    return 0;
}
