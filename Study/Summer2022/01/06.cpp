#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
using namespace std;
const int N = 114514;
namespace FastIO
{
    template <class T>
    inline void read(T &x)
    {
        x = 0;
        char c = getchar(), d = 0;
        while (c < '0' && c > '9')
            d = c, c = getchar();
        while (c >= '0' && c <= '9')
            x = (x << 1) + (x << 3) + c - '0', c = getchar();
        if (d == '-')
            x = -x;
    }
    template <class T>
    inline void wt(T x)
    {
        if (x / 10)
            wt(x / 10);
        putchar(x % 10 + '0');
    }
    template <class T>
    inline void wtln(T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        wt(x), putchar('\n');
    }
} // namespace FastIO
using namespace FastIO;
using pii = pair<int, int>;
int n, m[2];
int sum[2][N << 1];
struct node
{
    int l, r;
    bool operator<(const node &x) const { return l < x.l; }
} a[2][N];
priority_queue<int, vector<int>, greater<int>> id;
priority_queue<pii, vector<pii>, greater<pii>> pl;
void calc(bool op)
{
    while (!id.empty())
        id.pop();
    while (!pl.empty())
        pl.pop();
    for (int i = 1; i <= m[op]; i++)
        id.push(i);
    for (int i = 1; i <= m[op]; i++)
    {
        while (!pl.empty() && pl.top().first < a[op][i].l)
            id.push(pl.top().second), pl.pop();
        sum[op][id.top()]++;
        pl.push({a[op][i].r, id.top()});
        id.pop();
    }
    for (int i = 1; i <= n; i++)
        sum[op][i] += sum[op][i - 1];
}
int ans;
int main()
{
    // IO("airport");
    read(n), read(m[0]), read(m[1]);
    for (int i = 1; i <= m[0]; i++)
        read(a[0][i].l), read(a[0][i].r);
    for (int i = 1; i <= m[1]; i++)
        read(a[1][i].l), read(a[1][i].r);
    sort(a[0] + 1, a[0] + m[0] + 1);
    sort(a[1] + 1, a[1] + m[1] + 1);
    calc(0), calc(1);
    for (int i = 0; i <= n; i++)
        ans = max(ans, sum[0][i] + sum[1][n - i]);
    wtln(ans);
    return 0;
}