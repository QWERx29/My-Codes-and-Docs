#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 50;

int n, pre, ans;
int l[N], r[N];
int q[N], hd, tl;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    hd = 1, tl = 0;
    for (int i = 1; i <= n; i++)
    {
        while (hd <= tl && l[q[hd]] > r[i])
            pre = q[hd++];
        while (hd <= tl && l[q[tl]] <= l[i])
            --tl;
        q[++tl] = i;
        ans = max(ans, i - pre);
    }
    cout << ans << endl;
    return 0;
}