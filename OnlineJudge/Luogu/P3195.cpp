#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 50;

int n, l, h[N];
int q[N], hd, tl;
int s[N], f[N];

inline int k(int t) { return 2 * s[t]; }
inline int x(int t) { return s[t]; }
inline int y(int t) { return f[t] + s[t] * s[t] + 2 * s[t] * l; }
inline int sp(int t) { return t * t; }
inline double slope(int t, int u) { return 1.0 * (y(t) - y(u)) / (x(t) - x(u)); }

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> l, l++;
    for (int i = 1; i <= n; i++)
        cin >> h[i], h[i]++, s[i] = s[i - 1] + h[i];
    for (int i = 1; i <= n; i++)
    {
        while (hd < tl && slope(q[hd], q[hd + 1]) <= k(i))
            hd++;
        f[i] = f[q[hd]] + sp(s[i] - s[q[hd]] - l);
        while (hd < tl && slope(q[tl - 1], q[tl]) >= slope(q[tl - 1], i))
            tl--;
        q[++tl] = i;
    }
    cout << f[n] << endl;
    return 0;
}
