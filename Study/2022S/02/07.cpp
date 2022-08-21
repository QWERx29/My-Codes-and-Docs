#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000006;
const int B = 131;
const int P = 2147483647;
int n, ans, f[N], p[N], hs[N];
char s[N];
inline int dec(int x, int y) { return x - y < 0 ? x - y + P : x - y; }
inline int inc(int x, int y) { return x + y > P ? x + y - P : x + y; }
inline int mul(int x, int y) { return x * y > P ? x * y % P : x * y; }
inline int sum(int l, int r)
{
    if (l > r)
        return 0;
    return dec(f[r], mul(f[l - 1], p[r - l + 1]));
}
inline void hsh(int f[], const char str[])
{
    int l = strlen(str + 1);
    for (int i = 1; i <= l; i++)
        f[i] = inc(mul(f[i - 1], B), (str[i] - 'A' + 1));
}
inline bool qry(int pos)
{
    int pre = 0, nxt = 0, t = (n + 1) >> 1;
    if (pos == t)
    {
        pre = f[pos - 1], nxt = sum(pos + 1, n);
        return pre == nxt;
    }
    if (pos < t)
    {
        pre = inc(mul(f[pos - 1], p[t - pos]), sum(pos + 1, t));
        nxt = sum(t + 1, n);
        return pre == nxt;
    }
    if (pos > t)
    {
        pre = f[t - 1];
        nxt = inc(mul(sum(t, pos - 1), p[n - pos]), sum(pos + 1, n));
        return pre == nxt;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(hs, -1, sizeof hs);
    bool flag = false;
    cin >> n >> (s + 1);
    hsh(f, s);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = mul(p[i - 1], B);
    for (int i = 1; i <= n; i++)
    {
        if (qry(i))
        {
            ans++;
            if (hs[s[i] - 'A' + 1] != -1 && hs[s[i] - 'A' + 1] != i - 1)
                flag = true;
            hs[s[i] - 'A' + 1] = i;
        }
    }
    if (flag && ans > 1)
    {
        cout << "NOT UNIQUE\n";
        return 0;
    }
    if (ans < 1)
    {
        cout << "NOT POSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = (n + 1) >> 1;
        if (qry(i))
        {

            if (i == t)
            {
                for (int j = 1; j <= i - 1; j++)
                    putchar(s[j]);
                putchar('\n'), exit(0);
            }
            if (i < t)
            {
                for (int j = 1; j <= i - 1; j++)
                    putchar(s[j]);
                for (int j = i + 1; j <= t; j++)
                    putchar(s[j]);
                putchar('\n'), exit(0);
            }
            if (i > t)
            {
                for (int j = t; j <= i - 1; j++)
                    putchar(s[j]);
                for (int j = i + 1; j <= n; j++)
                    putchar(s[j]);
                putchar('\n'), exit(0);
            }
        }
    }
    return 0;
}