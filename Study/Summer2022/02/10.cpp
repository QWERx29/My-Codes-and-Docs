#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, M = 1e6 + 50;
const int L = 18;
int lst[M << 1], mx[N][L], st[N], lg[N], f[N];
int n, m, l, r, x;
inline int fnd(int l, int r)
{
    if (st[l] == l)
        return l;
    if (st[r] < l)
        return r + 1;
    int u = l, v = r;
    while (u <= v)
    {
        int mid = (u + v) >> 1;
        if (st[mid] < l)
            u = mid + 1;
        else
            v = mid - 1;
    }
    return u;
}
inline int qry(int l, int r)
{
    int x = lg[r - l + 1];
    return max(mx[l][x], mx[r - (1 << x) + 1][x]);
}
inline void init()
{
    cin >> n >> m;
    lg[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        st[i] = max(st[i - 1], lst[x + M] + 1);
        f[i] = i - st[i] + 1;
        lg[i] = lg[i >> 1] + 1;
        lst[x + M] = i;
    }
    for (int i = 1; i <= n; i++)
        mx[i][0] = f[i];
    for (int i = 1; i <= L; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
    }
}
inline void work()
{
    cin >> l >> r, l++, r++;
    int mid = fnd(l, r), ans = 0;
    if (mid > l)
        ans = mid - l;
    if (mid <= r)
        ans = max(ans, qry(mid, r));
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    while (m--)
        work();
    return 0;
}