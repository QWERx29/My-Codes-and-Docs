#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
struct node
{
    int l, r, _l, _r;
    inline int len() { return r - l + 1; }
    inline bool operator<(const node &x) const { return r - l < x.r - x.l; }
} a[N];
int dat[N << 1];
int n, m, cnt, ans = 2147483647;
#define ID(i) (lower_bound(dat + 1, dat + cnt + 1, i) - dat)
#define Lpos pos << 1
#define Rpos Lpos | 1
#define Lson Lpos, l, mid
#define Rson Rpos, mid + 1, r
#define mid ((l+r)>>1)
#define rt 1, 1, cnt
int tr[N << 4], tg[N << 4];
inline void psu(int pos) { tr[pos] = max(tr[Lpos], tr[Rpos]); }
inline void ntg(int pos, int v) { tr[pos] += v, tg[pos] += v; }
inline void psd(int pos)
{
    if (tg[pos])
        ntg(Lpos, tg[pos]), ntg(Rpos, tg[pos]), tg[pos] = 0;
}
inline void upd(int pos, int l, int r, int L, int R, int v)
{
    if(L <= l && r <= R) return ntg(pos, v), void();
    psd(pos);
    if (L <= mid)
        upd(Lson, L, R, v);
    if (R >= mid + 1)
        upd(Rson, L, R, v);
    psu(pos);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r, dat[++cnt] = a[i].l, dat[++cnt] = a[i].r;
    sort(dat + 1, dat + cnt + 1);
    cnt = unique(dat + 1, dat + cnt + 1) - dat;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i]._l = ID(a[i].l), a[i]._r = ID(a[i].r);
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        while (tr[1] < m && j < n)
            j++, upd(rt, a[j]._l, a[j]._r, 1);
        if (tr[1] < m)
            break;
        ans = min(ans, a[j].len() - a[i].len());
        upd(rt,a[i]._l,a[i]._r,-1);
    }
    if(ans==2147483647) ans=-1;
    cout<<ans<<endl;
    return 0;
}