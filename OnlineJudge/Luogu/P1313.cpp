#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 10007;
const int N = 2005;

int n, m, a, b, k, ans;
int c[N][N];

inline void init()
{
    c[1][1] = 1;
    for (int i = 0; i < N; i++)
        c[i][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

inline int qkpow(int x, int y)
{
    if (x == 1)
        return 1;
    int a = x, ans = 1;
    for (; y; y >>= 1)
    {
        if (y & 1 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> k >> n >> m;
    init();
    cout << (qkpow(a, n) * qkpow(b, m) * c[k][m]) % MOD;
    return 0;
}