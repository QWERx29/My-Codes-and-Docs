#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int n, p, m, ans, maxx, md, _l, _r;
int a[N], val[N], opt[N], q[N], w[N], dat[N], tag[N];
#define Lpos pos << 1
#define Rpos Lpos | 1
#define Lson Lpos, l, mid
#define Rson Rpos, mid + 1, r
#define mid ((l + r) >> 1)
#define rt 1, 1, n
#define This pos, l, r
#define Len (r - l + 1)
int tr[N << 4], tg[N << 4];
inline void psu(int pos) { dat[pos] = dat[Lpos] + dat[Rpos]; }
inline void bld(int pos, int l, int r)
{
    if (l == r)
        dat[pos] = val[l];
    else
        bld(Lson), bld(Rson), psu(pos);
}
inline void stg(int pos, int l, int r, int v)
{
    if (v == 1)
        tag[pos] = 1, dat[pos] = Len;
    if (v == 0)
        tag[pos] = 0, dat[pos] = 0;
}
inline void psd(int pos, int l, int r)
{
    stg(Lson, tag[pos]), stg(Rson, tag[pos]), tag[pos] = -1;
}
inline void upd(int pos, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R)
        return stg(This, v), void();
    psd(This);
    if (L <= mid)
        upd(Lson, L, R, v);
    if (R >= mid + 1)
        upd(Rson, L, R, v);
    psu(pos);
}
inline int qry_int(int pos, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return dat[pos];
    psd(This);
    if (R <= mid)
        return qry_int(Lson, L, R);
    if (L >= mid + 1)
        return qry_int(Rson, L, R);
    return qry_int(Lson, L, R) + qry_int(Rson, L, R);
}
inline int qry_pnt(int pos, int l, int r, int x)
{
    if (l == x && r == x)
        return dat[pos];
    psd(This);
    if (x <= mid)
        return qry_pnt(Lson, x);
    if (x >= mid + 1)
        return qry_pnt(Rson, x);
    return 0;
}
inline int chk(int x)
{
    memset(tag, -1, sizeof tag);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < x)
            val[i] = 0;
        else
            val[i] = 1;
    }
    bld(rt);
    for (int i = 1; i <= m; i++)
    {
        int cnt = qry_int(rt, q[i], w[i]);
        if (opt[i] == 0)
        {
            if (w[i] - cnt >= q[i])
                upd(rt, q[i], w[i] - cnt, 0);
            if (cnt)
                upd(rt, w[i] - cnt + 1, w[i], 1);
        }
        else
        {
            if (cnt)
                upd(rt, q[i], q[i] + cnt - 1, 1);
            if (w[i] >= q[i] + cnt)
                upd(rt, q[i] + cnt, w[i], 0);
        }
    }
    return qry_pnt(rt, p);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], maxx = max(a[i], maxx);
    for (int i = 1; i <= m; i++)
        cin >> opt[i] >> q[i] >> w[i];
    cin >> p;
    _l = 0, _r = maxx;
    while (_r >= _l)
    {
        md = (_l + _r) >> 1;
        if (chk(md))
            ans = md, _l = md + 1;
        else
            _r = md - 1;
    }
    cout << ans << endl;
    return 0;
}