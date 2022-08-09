#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 50;

int n, a, b, c, h[N];
int q[N], hd, tl;
int s[N], f[N];

inline int k(int t) { return 2 * a * s[t]; }
inline int x(int t) { return s[t]; }
inline int y(int t) { return f[t] + a * s[t] * s[t] - b * s[t]; }
inline int F(int t) { return a * t * t + b * t + c; }
inline double slope(int t, int u) { return 1.0 * (y(t) - y(u)) / (x(t) - x(u)); }

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; i++)
        cin >> h[i], s[i] = s[i - 1] + h[i];
    for (int i = 1; i <= n; i++)
    {
        while (hd < tl && slope(q[hd], q[hd + 1]) > k(i))
            hd++;
        f[i] = -k(i) * x(q[hd]) + y(q[hd]) + F(s[i]);
        while (hd < tl && slope(q[tl - 1], q[tl]) <= slope(q[tl], i))
            tl--;
        q[++tl] = i;
    }
    cout << f[n] << endl;
    return 0;
}
