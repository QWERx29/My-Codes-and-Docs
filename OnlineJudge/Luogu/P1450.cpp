#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 114514;
int dp[N], c[5], d[5], T;
int sum, res;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 4; i++)
        cin >> c[i];
    dp[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = c[i]; j < N; j++)
            dp[j] += dp[j - c[i]];
    cin >> T;
    while (T--)
    {
        res = 0;
        for (int i = 1; i <= 4; i++)
            cin >> d[i];
        cin >> sum;
        for (int i = 0; i <= 15; i++)
        {
            int tmp = sum, cnt = 0;
            for (int j = 1; j <= 4; j++)
                if ((i >> (j - 1)) & 1)
                    tmp -= c[j] * (d[j] + 1), cnt ^= 1;
            if (tmp < 0)
                continue;
            if (!cnt)
                res += dp[tmp];
            else
                res -= dp[tmp];
        }
        cout << res << endl;
    }
    return 0;
}