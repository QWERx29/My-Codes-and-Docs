#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 50;

int n, h[N], ans, t;
int stk[N], top;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t >> h[i];
    for (int i = 1; i <= n; i++)
    {
        while (top && h[i] < stk[top])
            --top, ++ans;
        if (h[i] > stk[top])
            stk[++top] = h[i];
    }
    cout << ans + top << endl;
    return 0;
}