#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5;

int n, m, k, a[N], s[N], ans;
int stk[N], top;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        cin >> k;
        memset(s, 0, sizeof s);
        memset(stk, 0, sizeof stk);
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i] - k;
        stk[top = 1] = ans = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] <= s[stk[top]])
                stk[++top] = i;
        for (int i = n; i > 1; i--)
        {
            if (s[i] >= s[stk[top]])
            {
                while (top > 1 && s[i] >= s[stk[top - 1]])
                    --top;
                ans = max(ans, i - stk[top]);
            }
        }
        cout << ans << " ";
    }

    return 0;
}
