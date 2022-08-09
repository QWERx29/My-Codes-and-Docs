#include <bits/stdc++.h>
using namespace std;
int n, a[305], f[305][305];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++)
        a[i] = a[i - n];
    a[2 * n + 1] = a[1];
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int j = 2; j <= n * 2; j++)
    {
        for (int i = j - 1; i > 0 && j - i < n; i--)
        {
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1]);
    cout << ans;
    return 0;
}