#include <bits/stdc++.h>
using namespace std;
using pid = pair<int, double>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
const int N = 1010;
vector<pid> e[N];
pdd dot[N];
int n, a, b, c, d, u;
inline double sq(double x) { return x * x; }
inline double dist(pdd x, pdd y) { return sqrt(sq(x.first - y.first) + sq(x.second - y.second)); }
double mn[N];
const double EPS = 1e-9;
double dis[N];
bool vis[N];
inline void dijkstra(int s)
{
    priority_queue<pdi> q;
    for (int i = 1; i <= n; i++)
        dis[i] = 1e10;
    dis[s] = 0, q.push({0, s});
    while (!q.empty())
    {
        pdi x = q.top();
        q.pop();
        int u = x.second;
        if (vis[u])
            continue;
        for (auto [v, w] : e[u])
            if (dis[v] - dis[u] - w > EPS)
                dis[v] = dis[u] + w, q.push({-dis[v], v});
    }
}
int main()
{
    // IO("fly");
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b >> c >> d >> u;
    for (int i = 1; i <= n; i++)
        mn[i] = 1e10;
    for (int i = 1; i <= n; i++)
        cin >> dot[i].first >> dot[i].second;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                if (mn[i] - dist(dot[i], dot[j]) > EPS)
                    mn[i] = dist(dot[i], dot[j]);
    mn[1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                if (dist(dot[i], dot[j]) + mn[j] - u > EPS)
                    continue;
                double t = (dist(dot[i], dot[j]) + mn[j] - mn[i]) * c + dist(dot[i], dot[j]) * d + a + b;
                e[i].push_back({j, t});
            }
    dijkstra(1);
    cout << fixed << setprecision(8) << dis[n] << '\n';
    return 0;
}