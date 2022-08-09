#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

int num[N], n, s, t, e, tol;
struct mat
{
    int a[505][505];
    inline mat(int op = 0)
    {
        memset(a, 0x3f, sizeof(a));
        if (op)
            for (int i = 1; i <= tol; i++)
                a[i][i] = 1;
    }
    inline mat operator*(const mat &b) const
    {
        mat c(0);
        for (int i = 1; i <= tol; i++)
            for (int j = 1; j <= tol; j++)
                for (int k = 1; k <= tol; k++)
                    c.a[j][k] = min(c.a[j][k], a[j][i] + b.a[i][k]);
        return c;
    }
} dis, ans;

inline void init()
{
    dis = mat(0);
    int x, y, z;
    cin >> n >> t >> s >> e;
    for (int i = 1; i <= t; i++)
    {
        cin >> x >> y >> z;
        if (!num[y])
            num[y] = ++tol;
        if (!num[z])
            num[z] = ++tol;
        dis.a[num[y]][num[z]] = dis.a[num[z]][num[y]] = x;
    }
}
inline void qkpow()
{
    n--;
    ans = dis;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ans = ans * dis;
        dis = dis * dis;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    init();
    qkpow();
    cout << ans.a[num[s]][num[e]];
    return 0;
}