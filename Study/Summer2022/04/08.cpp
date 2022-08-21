#include <bits/stdc++.h>
namespace FastIO
{
    template <class T>
    inline void read(T &x)
    {
        x = 0;
        char c = getchar(), d = 0;
        while (c < '0' || c > '9')
            d = c, c = getchar();
        while (c >= '0' && c <= '9')
            x = (x << 3) + (x << 1) + c - '0', c = getchar();
        if (d == '-')
            x = -x;
    }
    template <class T>
    inline void wt(T x)
    {
        if (x / 10)
            wt(x / 10);
        putchar(x % 10 + '0');
    }
    template <class T>
    inline void wtln(T x)
    {
        if (x < 0)
            x = -x, putchar('-');
        wt(x), putchar('\n');
    }
}
using namespace FastIO;
const int N = 5e5 + 50, M = 4.2e6 + 50, E = 1e7 + 10;
int n, m, s;
int hd[M], tot = 1;
struct edge
{
    int nx, to, val;
} e[E];
inline void adde(int u, int v, int w)
{
    e[tot] = {hd[u], v, w};
    hd[u] = tot++;
}
#define rt 1, 1, n
#define mid ((l + r) >> 1)
#define Lpos (pos << 1)
#define Rpos (Lpos | 1)
#define Lson Lpos, l, mid
#define Rson Rpos, mid + 1, r
#define This pos, l, r
#define in(x) x
#define out(x) (x + (n << 2))
#define P ((n << 3) + cnt)
int numb[N], cnt = 1;
inline void bld(int pos, int l, int r)
{
    adde(out(pos), in(pos), 0);
    if (l == r)
        return numb[l] = pos, void();
    adde(in(Lpos), in(pos), 0), adde(in(Rpos), in(pos), 0);
    adde(out(pos), out(Lpos), 0), adde(out(pos), out(Rpos), 0);
    bld(Lson), bld(Rson);
}
inline void upd(int pos, int l, int r, int L, int R, bool op)
{
    if (L <= l && r <= R)
    {
        if (op == 0)
            adde(in(pos), P, 0);
        if (op == 1)
            adde(P, out(pos), 1);
        return;
    }
    if (L <= mid)
        upd(Lson, L, R, op);
    if (R >= mid + 1)
        upd(Rson, L, R, op);
}
std::deque<int> q;
int dis[M];
inline void bfs()
{
    memset(dis, 0x3f, sizeof dis);
    dis[numb[s]] = 0;
    q.push_back(numb[s]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (int i = hd[u]; i; i = e[i].nx)
        {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (w)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}

signed main()
{
    read(n), read(m), read(s);
    bld(rt);
    int a, b, c, d;
    for (int i = 1; i <= m; i++)
    {
        read(a), read(b), read(c), read(d);
        upd(rt, a, b, 0), upd(rt, c, d, 1);
        cnt++;
        upd(rt, a, b, 1), upd(rt, c, d, 0);
        cnt++;
    }
    bfs();
    for (int i = 1; i <= n; i++)
        wtln(dis[in(numb[i])]);
    return 0;
}
