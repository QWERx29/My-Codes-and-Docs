#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;

#define Mid ((l + r) >> 1)
#define Lpos (pos << 1)
#define Rpos (Lpos | 1)
#define Lson Lpos, l, Mid
#define Rson Rpos, Mid + 1, r
#define Len (r - l + 1)
#define Root 1, 1, n
#define This pos, l, r

int tag[N << 2];
struct node
{
    int pre, suf, ans, len;
    inline node operator+(const node &r) const
    {
        node res;
        res.len = len + r.len;
        res.pre = pre == len ? len + r.pre : pre;
        res.suf = r.suf == r.len ? r.len + suf : r.suf;
        res.ans = max(suf + r.pre, max(ans, r.ans));
        return res;
    }
    inline node init(int l, int v)
    {
        node res;
        res.len = v;
        if (l == 1)
            res.pre = res.suf = res.ans = v;
        else
            res.pre = res.suf = res.ans = 0;
        return res;
    }
} dat[N << 2];

inline void upd(int pos)
{
    dat[pos] = dat[Lpos] + dat[Rpos];
}
inline void stg(int pos, int l, int r, int v)
{
    if (v == -1)
        return;
    tag[pos] = v;
    dat[pos] = dat[pos].init(v, Len);
}
inline void psd(int pos, int l, int r)
{
    if (tag[pos] == -1)
        return;
    stg(Lson, tag[pos]), stg(Rson, tag[pos]), tag[pos] = -1;
}
inline void update(int pos, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R)
        return stg(This, v), void();
    psd(This);
    if (L <= Mid)
        update(Lson, L, R, v);
    if (R > Mid)
        update(Rson, L, R, v);
    upd(pos);
}
inline int qry(int pos, int l, int r, int p)
{
    if (l == r)
        return l;
    if (dat[pos].ans < p)
        return 0;
    psd(This);
    if (dat[Lpos].ans >= p)
        return qry(Lson, p);
    if (dat[Lpos].suf + dat[Rpos].pre >= p)
        return Mid - dat[Lpos].suf + 1;
    return qry(Rson, p);
}
inline void bld(int pos, int l, int r)
{
    tag[pos] = -1;
    if (l == r)
        return dat[pos] = dat[pos].init(1, 1), void();
    bld(Lson), bld(Rson), upd(pos);
}

int main()
{
    int n, q;
    cin >> n >> q;
    bld(Root);
    for (int i = 1; i <= q; i++)
    {
        int op, x, d;
        cin >> op;
        if (op == 1)
        {
            cin >> d;
            x = qry(Root, d);
            cout << x << endl;
            if (x)
                update(Root, x, min(x + d - 1, n), 0);
        }
        if (op == 2)
        {
            cin >> x >> d;
            update(Root, x, min(x + d - 1, n), 1);
        }
    }
    return 0;
}