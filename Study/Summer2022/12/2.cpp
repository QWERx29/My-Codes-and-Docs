#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int n, m, cnt, pnt[N];
double ans = 0x7fffffff;
struct edge
{
    int nx, to, val;
    double w;
    inline bool operator<(const edge &o) { return w < o.w; }
} e[N << 1];
inline void adde(int u, int v, int w) { e[++cnt].nx = u, e[cnt].to = v, e[cnt].val = w; }
inline int getpnt(int x) { return x == pnt[x] ? x : pnt[x] = getpnt(pnt[x]); }
inline double kruskal()
{
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++)
        pnt[i] = i;
    int tot = 0;
    double res = 0;
    for (int i = 1; i <= m; i++)
    {
        int _1 = getpnt(e[i].nx), _2 = getpnt(e[i].to);
        if (_1 != _2)
        {
            pnt[_1] = _2, ++tot, res += e[i].w;
            if (tot == n - 1)
                break;
        }
    }
    return res;
}
inline double mul(double x) { return x * x; }
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, adde(x, y, z);
    for (int i = 1; i <= m; i++)
        e[i].w = e[i].val;
    int _1 = kruskal();
    for (int i = 1; i <= m; i++)
        e[i].w = -e[i].val;
    int _2 = -kruskal();
    for (int j = _1; j <= _2; j++)
    {
        double a = j * 1.0 / (n - 1);
        for (int i = 1; i <= m; i++)
            e[i].w = mul(e[i].val - a);
        ans = min(ans, kruskal());
    }
    cout << fixed << setprecision(4) << sqrt(ans / (n - 1)) << '\n';
    return 0;
}