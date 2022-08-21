#include <bits/stdc++.h>
using namespace std;
const int N = 1145141;
const int M = N * 3;
inline void read(int &x)
{
    x = 0;
    char c = getchar(), d = 0;
    while (c < '0' || c > '9')
        d = c, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + c - '0', c = getchar();
    if (d == '-')
        x = -x;
}
struct edge
{
    int nx, to;
    bool l;
} e[M];
int hd[N], p, df, tot;
int in[N], dis[N], low[N], dfn[N], siz[N], f[N], st[N], tl[N];
inline void adde(bool op, int u, int v)
{
    e[++p].l = op;
    e[p].nx = hd[u], e[p].to = v;
    hd[u] = p;
    if (!tl[u])
        tl[u] = p;
}
inline void tarjan(int u)
{
    low[st[++p] = u] = dfn[u] = ++df;
    for (int i = hd[u], v; i; i = e[i].nx)
    {
        if (e[i].l)
            continue;
        if (!dfn[v = e[i].to])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (!f[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++tot;
        do
        {
            ++siz[f[st[p]] = u];
        } while (st[p--] != u);
    }
}
int main()
{
    int p = 0, n, k, s, op, x, y, cnt = 0;
    read(n), read(k);
    s = n + 1;
    long long ans = n;
    for (int i = 1; i <= k; i++)
    {
        read(op), read(x), read(y);
        if (op == 1)
            adde(0, x, y), adde(0, y, x);
        else if (op == 2)
            adde(1, x, y);
        else if (op == 3)
            adde(0, y, x);
        else if (op == 4)
            adde(1, y, x);
        else if (op == 5)
            adde(0, x, y);
    }
    for (int i = 1; i <= n; ++i)
        adde(0, s, i);
    tarjan(s);
    for (int i = 1; i <= s; ++i)
    {
        x = f[i];
        for (int j = hd[i]; j; j = e[j].nx)
        {
            y = e[j].to = f[e[j].to]; //改一下
            if (x != y)
                ++in[y];
            else if (e[j].l)
                puts("-1"), exit(0);
        }
    }
    for (int i = 1; i <= s; ++i)
        if (i != f[i])
            e[tl[i]].nx = hd[f[i]], hd[f[i]] = hd[i];
    st[p = 1] = s;
    while (p)
    {
        ++cnt;
        ans += dis[x = st[p--]] * siz[x];
        for (int i = hd[x]; i; i = e[i].nx)
        {
            y = e[i].to;
            dis[y] = max(dis[y], dis[x] + e[i].l);
            if (!--in[y])
                st[++p] = y;
        }
    }
    cout << (cnt < tot ? -1 : ans) << '\n';
    return 0;
}