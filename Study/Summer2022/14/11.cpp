#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
using edge = pair<int, int>;
int n, m, u, v;
vector<edge> e[N];
int cnt, deg[N];
inline void adde(int u, int v)
{
    cnt++;
    e[u].push_back(make_pair(v, cnt));
    e[v].push_back(make_pair(u, cnt));
}
int tot, bcc, top, dfn[N], low[N], bel[N], stk[N];
inline void form(int id)
{
    bcc++;
    for (int x = 0; x != id;)
        bel[x = stk[top--]] = bcc;
}
inline void tarjan(int u, int pre = 0)
{
    dfn[u] = low[u] = ++tot, stk[++top] = u;
    for (auto ee : e[u])
    {
        int v = ee.first;
        if (ee.second == pre)
            continue;
        if (!dfn[v])
        {
            tarjan(v, ee.second), low[u] = min(low[u], low[v]);
            if(low[v]>dfn[u])
                form(v);
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
    if(!pre)
        form(u);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> u >> v, adde(u, v);
    tarjan(1);
    for (int u = 1; u <= n; u++)
    {
        for (auto ee : e[u])
        {
            int v = ee.first;
            if (u < v && bel[u] != bel[v])
                deg[bel[u]]++, deg[bel[v]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= bcc; i++)
        if (deg[i] == 1)
            ans++;
    cout << ((ans + 1) >> 1) << endl;
    return 0;
}