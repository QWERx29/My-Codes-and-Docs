#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int N = 2e5 + 50;
const int B = 2e5 + 3;
int n, bst, cnt, ans[N], a[N];
ll pw[N], hs[N], rh[N];
set<ll> st;
inline void init(int n)
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * B;
        hs[i] = hs[i - 1] * B + a[i];
        rh[i] = rh[i - 1] * B + a[n - i + 1];
    }
}
inline ll hsh(int l, int r) { return hs[r] - hs[l - 1] * pw[r - l + 1]; }
inline ll rhs(int l, int r) { return rh[n - l + 1] - rh[n - r] * pw[r - l + 1]; }
inline void chk(int v, int i)
{
    if (v > bst)
        bst = v, cnt = 0;
    if (v == bst)
        ans[++cnt] = i;
}
inline int cal(int l)
{
    int res = 0;
    st.clear();
    for (int i = l; i <= n; i += l)
    {
        int h1 = hsh(i - l + 1, i), h2 = rhs(i - l + 1, i);
        if (st.count(h1) || st.count(h2))
            continue;
        st.insert(h1);
        ++res;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(n);
    for (int i = 1; i <= n; i++)
        if (n / i >= bst)
            chk(cal(i), i);
    cout << bst << " " << cnt << '\n';
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << " \n"[i == cnt];
    return 0;
}