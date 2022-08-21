#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 50;

int n, k, e[N];
int dp[N];
int q[N], hd, tl;

inline int f(int i)
{
    return i ? dp[i - 1] - e[i] : 0;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> e[i], e[i] += e[i - 1];
    hd = tl = 1;
    for (int i = 1; i <= n; i++)
    {
        while (hd <= tl && q[hd] < i - k)
            hd++;
        while (hd <= tl && f(i) >= f(q[tl]))
            tl--;
        q[++tl] = i;
        dp[i] = e[i] + f(q[hd]);
    }
    cout << dp[n] << endl;
    return 0;
}