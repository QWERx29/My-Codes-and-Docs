#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
using edge = pair<int, int>;
int n, m, x, y;
vector<edge> e[N];
int cnt;
inline void adde(int u, int v)
{
    cnt++;
    e[u].push_back(make_pair(v, cnt));
    e[v].push_back(make_pair(u, cnt));
}
int tot, bcc, top, dfn[N], low[N], bel[N], stk[N];
bool bridge[N];
inline void tarjan(int u, int pre = 0)
{
    dfn[u] = low[u] = ++tot, stk[++top] = u;
    for (auto ee : e[u])
    {
        int v = ee.first;
        if (ee.second == pre)
            continue;
        if (!dfn[v])
            tarjan(v, ee.second), low[u] = min(low[u], low[v]);
        else
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++bcc, bridge[pre] = true;
        int v;
        do
        {
            v = stk[top--], bel[v] = bcc;
        } while (v != u);
    }
}
void init()
{
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(bel, 0, sizeof bel);
    memset(bridge, 0, sizeof bridge);
    cnt = tot = top = bcc = 0;
    for (int i = 1; i <= n; i++)
        e[i].clear();
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        init();
        for (int i = 1; i <= m; i++)
            cin >> x >> y, adde(x, y);
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        int ans = 0;
        for (int i = 1; i <= m; i++)
            if (bridge[i])
                ans++;
        cout << ans << endl;
    }
    return 0;
}