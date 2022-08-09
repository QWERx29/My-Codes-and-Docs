#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int a[114514], n, mgcd = 1 << 30;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mgcd = min(mgcd, a[i]);
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * (a[i] / mgcd) % MOD;
    cout << mgcd << " " << ans << endl;
    return 0;
}