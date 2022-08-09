#include <bits/stdc++.h>
#define N 114514
using namespace std;
namespace IO
{
    template <class T>
    void read(T &x)
    {
        x = 0;
        char c = getchar(), d = 0;
        while (!isdigit(c))
            d = c, c = getchar();
        while (isdigit(c))
            x = x * 10 + c - '0', c = getchar();
        if (d == '-')
            x = -x;
    }
    template <class T>
    void wt(T x)
    {
        if (x / 10)
            wt(x / 10);
        putchar(x % 10 + '0');
    }
    template <class T>
    void write(T x)
    {
        if (x < 0)
            x = -x, putchar('-');
        wt(x);
    }
#define space(x) write(x), putchar(' ')
#define enter(x) write(x), putchar('\n')
} // namespace IO
using namespace IO;
typedef pair<int, int> pii;
struct node
{
    int l, r;
    bool operator<(const node &x) const { return l < x.l; }
} a[2][N];
priority_queue<int, vector<int>, greater<int>> id;
priority_queue<pii, vector<pii>, greater<pii>> pl;
int n, m[2];
int sum[2][N << 1];
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
    enter(ans);
    return 0;
}
