#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 50;

int n, a[N], s[N], f[N], g[N];
int q[N], hd, tl;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = n; i >= 1; i--)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        while (hd < tl && s[q[hd + 1]] + g[q[hd + 1]] <= s[i])
            hd++;
        f[i] = f[q[hd]] + 1;
        g[i] = s[i] - s[q[hd]];
        while (hd < tl && s[q[tl]] + g[q[tl]] >= s[i] + g[i])
            tl--;
        q[++tl] = i;
    }
    cout << f[n] << endl;
    return 0;
}