#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 55, M = 455;
int n, m, e;
int a[N][M], s[N];
vector<pii> op;
inline void move(int fr, int to)
{
    if (fr == to)
        return;
    if (op.empty() || *op.rbegin() != pii(to, fr))
        op.push_back({fr, to});
    else
        op.pop_back();
    a[to][++s[to]] = a[fr][s[fr]--];
}
inline void repmv(int fr, int to, int t)
{
    for (int i = 1; i <= t; i++)
        move(fr, to);
}
inline bool check(int x, int lw, int up)
{
    return lw <= x && x <= up;
}
inline int getValidRow(int cur)
{
    if (cur != 1 && e != 1)
        return 1;
    if (cur != 2 && e != 2)
        return 2;
    return 3;
}
inline int count(int r, int lw, int up)
{
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (check(a[r][i], lw, up))
            ++res;
    return res;
}
inline int shift(int r, int lw, int up)
{
    int cnt = count(r, lw, up);
    int t = getValidRow(r);
    bool skipable = true;
    for (int i = 1; i <= m - cnt; i++)
        if (check(a[r][i], lw, up))
            skipable = false;
    if (skipable)
        return cnt;
    if (cnt > m - cnt)
    {
        repmv(t, e, m - cnt);
        for (int i = m; i >= 1; i--)
            move(r, check(a[r][i], lw, up) ? e : t);
        repmv(t, r, m - cnt);
        repmv(e, r, cnt);
        repmv(e, t, m - cnt);
    }
    else
    {
        repmv(t, e, cnt);
        for (int i = m; i >= 1; i--)
            move(r, check(a[r][i], lw, up) ? t : e);
        repmv(e, r, m - cnt);
        repmv(t, r, cnt);
        repmv(e, t, cnt);
    }
    return cnt;
}
inline void adjust(int fixed = 0)
{
    for (int i = 1; i <= n + 1; i++)
        if (i != fixed && s[i] < s[e])
            e = i;
    for (int i = 1; i <= n + 1; i++)
        if (i != e && s[i] < m)
            repmv(e, i, m - s[i]);
}
inline void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    for (int i = 1; i <= n + 1; i++)
        if (i != e)
            shift(i, l, mid);
    for (int i = 1; i <= n + 1; i++)
    {
        if (i == e)
            continue;
        int cnt = count(i, l, mid);
        if (cnt == m || cnt == 0)
            continue;
        if (m - s[e] >= cnt)
            repmv(i, e, cnt);
        else
            repmv(i, e, m - s[e]), adjust(i), shift(i--, l, mid);
    }
    adjust();
    solve(l, mid), solve(mid + 1, r);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        s[i] = m;
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    e = n + 1;
    solve(1, n);
    cout << op.size() << endl;
    for (auto x : op)
        cout << x.first << " " << x.second << endl;
    return 0;
}
