#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int n, m, pnt[N], cal[N], cnt[N], odd[N], ans;
inline int getpnt(int x) { return x == pnt[x] ? x : pnt[x] = getpnt(pnt[x]); }
inline void merge(int x, int y)
{
    int _1 = getpnt(x), _2 = getpnt(y);
    if (_1 != _2)
        pnt[_1] = _2;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    while (cin >> n >> m)
    {
        memset(cal, 0, sizeof cal);
        memset(cnt, 0, sizeof cnt);
        memset(odd, 0, sizeof odd);
        for (int i = 1; i <= n; i++)
            pnt[i] = i;
        for (int i = 1, a, b; i <= m; i++)
            cin >> a >> b, cal[a]++, cal[b]++, merge(a, b);
        for (int i = 1; i <= n; i++)
        {
            cnt[getpnt(i)]++;
            if (cal[i] & 1)
                odd[getpnt(i)]++;
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] <= 1)
                continue;
            else if (odd[i] == 0)
                ans++;
            else if (odd[i] > 0)
                ans += odd[i] >> 1;
        }
        cout << ans << endl;
    }
    return 0;
}