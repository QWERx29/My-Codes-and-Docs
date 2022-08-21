#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 50;

int mx[N], mxh, mxt;
int mn[N], mnh, mnt;
int n, k, ans, h[N];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
    {
        while (mxh <= mxt && abs(h[mx[mxh]] - h[i]) > k)
            mxh++;
        while (mnh <= mnt && abs(h[i] - h[mn[mnh]]) > k)
            mnh++;
        ans = max(ans, i - max(mx[mxh - 1], mn[mnh - 1]));
        while (mxh <= mxt && h[mx[mxt]] <= h[i])
            mxt--;
        mx[++mxt] = i;
        while (mnh <= mnt && h[mn[mnt]] >= h[i])
            mnt--;
        mn[++mnt] = i;
    }
    cout << ans << endl;
    return 0;
}