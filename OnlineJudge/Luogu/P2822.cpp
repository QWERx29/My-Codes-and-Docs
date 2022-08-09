#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2005;

int n, m, k, t;
int c[N][N], ans[N][N];

void init()
{
    c[1][1] = 1;
    for (int i = 0; i < N; i++)
        c[i][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (c[i][j] == 0)
                ans[i][j] += 1;
        }
        ans[i][i + 1] = ans[i][i];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> t >> k;
    init();
    while (t--)
    {
        cin >> n >> m;
        if (m > n)
            m = n;
        cout << ans[n][m] << endl;
    }
    return 0;
}