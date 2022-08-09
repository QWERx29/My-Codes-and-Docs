#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[35], rt[35][35], dp[35][35];
inline void dfs(int l, int r)
{
    if (l > r)
        return dp[l][r] = 1, void();
    if (l == r)
        return dp[l][r] = a[l], rt[l][r] = l, void();
    for (int i = l; i <= r; i++)
    {
        if (!dp[l][i - 1])
            dfs(l, i - 1);
        if (!dp[i + 1][r])
            dfs(i + 1, r);
        if (dp[l][r] < dp[l][i - 1] * dp[i + 1][r] + a[i])
            dp[l][r] = dp[l][i - 1] * dp[i + 1][r] + a[i], rt[l][r] = i;
    }
}
inline void print(int l, int r)
{
    if (rt[l][r])
    {
        cout << rt[l][r] << " ";
        print(l, rt[l][r] - 1);
        print(rt[l][r] + 1, r);
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, n);
    cout << dp[1][n] << endl;
    print(1, n);
    return 0;
}