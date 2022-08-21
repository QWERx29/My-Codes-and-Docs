#include <bits/stdc++.h>
using namespace std;
char str[1010];
bitset<1010> mat[2022];
inline int Gauss(int n, int m)
{
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        while (cur <= m && !mat[cur].test(i))
            cur++;
        if (cur > m)
            return 0;
        ans = max(ans, cur);
        if (cur != i)
            swap(mat[cur], mat[i]);
        for (int j = 1; j <= m; j++)
            if (i != j && mat[j].test(i))
                mat[j] ^= mat[i];
    }
    return ans;
}
signed main()
{
    int n, m;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, res; i <= m; i++)
    {
        cin >> (str + 1) >> res;
        for (int j = 1; j <= n; j++)
            mat[i].set(j, str[j] == '1');
        mat[i].set(0, res);
    }
    int ret = Gauss(n, m);
    if (ret)
    {
        cout << ret << "\n";
        for (int i = 1; i <= n; i++)
            cout << (mat[i].test(0) ? "?y7M#" : "Earth") << "\n";
    }
    else
        cout << "Cannot Determine\n";
    return 0;
}