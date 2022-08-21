#include <bits/stdc++.h>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
using namespace std;
namespace Math
{
    const int M = 998244353;
    typedef long long ll;
    inline int Mod(int x, int P = M) { return (x % P + P) % P; }
    inline int Mul(ll x, int y) { return x * y % M; }
    inline int Inc(int x, int y) { return x + y < M ? x + y : x + y - M; }
    inline int Dec(int x, int y) { return x - y < 0 ? x - y + M : x - y; }
    inline int Pow(int x, int t)
    {
        int r = 1;
        for (t = Mod(t, M - 1); t; x = Mul(x, x), t >>= 1)
            if (t & 1)
                r = Mul(r, x);
        return r;
    }
    inline int Div(int x, int y) { return Mul(x, Pow(y, -1)); }
} // namespace Math
using namespace Math;
const int N = 350;
int n, m;
int a[N][N], x[N], p[N], c, q;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // IO("LA");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        cin >> a[i][m + 1];
    for (int k = 1, l = 1, t = 0; l <= m; k++, l++, t = 0)
    {
        while (l <= m)
        {
            for (int i = k; t == 0 && i <= n; i++)
                if (a[i][l])
                    t = i;
            if (t)
                break;
            q = l++;
        }
        if (l > m)
            break;
        p[++c] = l;
        if (t ^ k)
            for (int j = l; j <= m + 1; j++)
                swap(a[k][j], a[t][j]);
        t = Pow(a[k][l], -1);
        for (int j = l; j <= m + 1; j++)
            a[k][j] = Mul(a[k][j], t);
        for (int i = k + 1; i <= n; i++)
        {
            if (a[i][l] == 0)
                continue;
            t = a[i][l];
            for (int j = l; j <= m + 1; j++)
                a[i][j] = Dec(a[i][j], Mul(a[k][j], t));
        }
    }
    for (int k = c, l = p[c], t; k >= 1; l = p[--k])
    {
        for (int i = 1; i < k; i++)
        {
            if (a[i][l] == 0)
                continue;
            t = a[i][l];
            for (int j = l; j <= m + 1; j++)
                a[i][j] = Dec(a[i][j], Mul(a[k][j], t));
        }
    }
    for (int i = c + 1; i <= n; i++)
        if (a[i][m + 1])
            cout<<"?"<<endl, exit(0);
    if (c == m)
    {
        for (int i = 1; i <= m; i++)
            cout << a[i][m + 1] << " ";
        cout << endl;
    }
    else
    {
        cout<<"!"<<endl;
        for (int i = 1; i <= c; i++)
            x[p[i]] = a[i][m + 1];
        for (int i = 1; i <= m; i++)
            cout << x[i] << " ";
        cout << endl;
        ++x[q];
        for (int i = 1; i <= c; i++)
            x[p[i]] = Dec(x[p[i]], a[i][q]);
        for (int i = 1; i <= m; i++)
            cout << x[i] << " ";
        cout << endl;
    }
    return 0;
}