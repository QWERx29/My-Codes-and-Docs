#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int mxq[N], mnq[N];
int D, ans, n, hx, rx, hn, rn;
struct node
{
    int x, y;
    bool operator<(const node &o) const { return x < o.x; }
} a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> D;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    hx = hn = 1;
    ans = 2e9;
    int L = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (hx <= rx && a[mxq[rx]].y < a[i].y)
            rx--;
        mxq[++rx] = i;
        while (hn <= rn && a[mnq[rn]].y > a[i].y)
            rn--;
        mnq[++rn] = i;
        while (L <= i && a[mxq[hx]].y - a[mnq[hn]].y >= D)
        {
            ans = min(ans, a[i].x - a[L].x);
            L++;
            while (hx <= rx && mxq[hx] < L)
                hx++;
            while (hn <= rn && mnq[hn] < L)
                hn++;
        }
    }
    cout << (ans < 2e9 ? ans : -1) << '\n';
    return 0;
}
