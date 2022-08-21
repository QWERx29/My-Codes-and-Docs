#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
const int MOD = 1e9 + 7;
inline int mul(ll x, ll y) { return x * y % MOD; }
inline int inc(int x, int y) { return x + y < MOD ? x + y : x + y - MOD; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + MOD : x - y; }
int n, k;
int dp[N][N], pre[N][N], suf[N][N];
int L[N], R[N];
char s[N];
inline bool isLB(int i) { return s[i] == '(' || s[i] == '?'; }
inline bool isRB(int i) { return s[i] == ')' || s[i] == '?'; }
inline bool isST(int i) { return s[i] == '*' || s[i] == '?'; }
inline void save(int l, int r, int val)
{
    dp[l][r] = val;
    pre[l][r] = inc(pre[l][r - 1], val);
    suf[l][r] = inc(suf[l + 1][r], val);
}
inline int validSuf(int l, int r)
{
    int ml = min(k, min(L[l] - l, r - l + 1));
    return dec(suf[l][r], suf[l + ml + 1][r]);
}
inline int validPre(int l, int r)
{
    int ml = min(k, min(r - R[r], r - l + 1));
    return dec(pre[l][r - 1], pre[l][r - ml - 1]);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k >> (s + 1);
    for (int i = 1; i <= n; i++)
    {
        L[i] = R[i] = i;
        while (isST(L[i]))
            ++L[i];
        while (isST(R[i]))
            --R[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1, r; l + len - 1 <= n; l++)
        {
            r = l + len - 1;
            if (!isLB(l))
            {
                save(l, r, 0);
                continue;
            }
            int res = 0;
            for (int i = l + 1; i <= r; i++)
            {
                if (!isRB(i))
                    continue;
                int resL = 0;
                if (L[l + 1] >= i && i - l - 1 <= k)
                    ++resL;
                resL = inc(resL, validSuf(l + 1, i - 1));
                resL = inc(resL, validPre(l + 1, i - 1));
                int resR = i == r ? 1 : validSuf(i + 1, r);
                res = inc(res, mul(resL, resR));
            }
            save(l, r, res);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}