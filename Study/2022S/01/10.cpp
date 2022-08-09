#include <bits/stdc++.h>
using namespace std;
const int N = 114514 * 3;
int fa[N], n, k, ans;
inline int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void uni(int x, int y)
{
    fa[find(x)] = find(y);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x, y, op;
    cin >> n >> k;
    for (int i = 1; i <= n * 3; i++)
        fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (op == 1)
        {
            if (find(x + n) == find(y) || find(x) == find(y + n))
                ans++;
            else
                uni(x, y), uni(x + n, y + n), uni(x + 2 * n, y + 2 * n);
        }
        else if (op == 2)
        {
            if (find(x) == find(y) || find(x) == find(y + n))
                ans++;
            else
                uni(x + n, y), uni(x + n * 2, y + n), uni(x, y + n * 2);
        }
    }
    cout << ans << endl;
    return 0;
}