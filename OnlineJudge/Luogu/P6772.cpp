#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 255, L = 32;
const ll INF = 1e18;
int S;
struct matrix
{
    ll d[N][N];
    matrix() { memset(d, 0xc0, sizeof d); }
    inline ll *operator[](int i) { return d[i]; }
    inline const ll *operator[](int i) const { return d[i]; }
} pw[L];
int n, m, T, k, u, v, w;
int c[N];
ll dp[N], tmp[N];
#define pos(x, t) (((x)-1) * 5 + (t))
inline void mat_mul(const matrix &a, const matrix &b, matrix &r)
{
    memset(r.d, 0xc0, sizeof r.d);
    for (int i = 0; i < S; i++)
    {
        for (int k = 0; k < S; k++)
        {
            ll t = a[i][k];
            for (int j = 0; j < S; j++)
                r[i][j] = max(r[i][j], t + b[k][j]);
        }
    }
}
inline void init()
{
    for (int i = 1; i < L; i++)
        mat_mul(pw[i - 1], pw[i - 1], pw[i]);
    memset(dp, 0xc0, sizeof dp);
    dp[pos(1, 0)] = c[1];
}
inline void mul(int t)
{
    memset(tmp, 0xc0, sizeof tmp);
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
            tmp[i] = max(tmp[i], dp[j] + pw[t][j][i]);
    for (int i = 0; i < S; i++)
        dp[i] = tmp[i];
}
inline void apply(int t)
{
    for (int i = 0; i < L; i++)
        if (t & (1 << i))
            mul(i);
}
struct node
{
    int t, x, y;
    inline bool operator<(const node &x) const { return t < x.t; }
} a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> T >> k, S = n * 5;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        for (int j = 1; j < 5; j++)
            pw[0][pos(i, j - 1)][pos(i, j)] = 0;
    }
    for (int i = 1; i <= m; i++)
        cin >> u >> v >> w, pw[0][pos(u, w - 1)][pos(v, 0)] = c[v];
    init();
    for (int i = 1; i <= k; i++)
        cin >> a[i].t >> a[i].x >> a[i].y;
    sort(a + 1, a + k + 1);
    for (int i = 1; i <= k; i++)
        apply(a[i].t - a[i - 1].t), dp[pos(a[i].x, 0)] += a[i].y;
    apply(T - a[k].t);
    cout << (dp[pos(1, 0)] < -INF ? -1 : dp[pos(1, 0)]) << "\n";
    return 0;
}