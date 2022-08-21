#include <bits/stdc++.h>
using namespace std;
using db = double;
const int N = 11451;
const db EPS = 1e-12;
int T, n;
db a[N], b[N], c[N];
db x, mx = 0, l, r, lmid, rmid;
inline db cal(db x)
{
    db maxx = -0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
        maxx = max(maxx, a[i] * x * x + b[i] * x + c[i]);
    return maxx;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof a), memset(b, 0, sizeof b), memset(c, 0, sizeof c);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> c[i];
        l = 0, r = N;
        while (r - l > EPS)
        {
            lmid = (l * 2 + r) / 3, rmid = (l + r * 2) / 3;
            if (cal(lmid) <= cal(rmid))
                r = rmid;
            else
                l = lmid;
        }
        cout << fixed << setprecision(4) << cal(l) << endl ;
    }
    return 0;
}
