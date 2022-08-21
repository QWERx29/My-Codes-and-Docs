#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
char ch, s[N];
int f[N], a[N], id[N];
int n, k, m, mid, r, x;
inline bool ltr()
{
    if (ch <= 'Z' && ch >= 'A')
        return 1;
    ch -= 32;
    if (ch <= 'Z' && ch >= 'A')
        return 1;
    return 0;
}
int main()
{
    a[n] = -2, a[++n] = -1;
    while (scanf("%c", &ch) != EOF)
    {
        s[++k] = ch;
        if (ltr())
            a[++n] = int(ch), id[n] = k, a[++n] = -1;
    }
    a[++n] = -3;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        if (i < r)
            f[i] = max(f[r * 2 - i], r - i + 1);
        while (a[i + f[i]] == a[i - f[i]])
            f[i]++;
        if (i + f[i] - 1 > r)
            r = i + f[i] - 1, mid = i;
        if (f[i] > m)
            m = f[i], x = i;
    }
    printf("%d\n", m - 1);
    int q = x - m + 2, w = x + m - 2;
    for (int i = id[q]; i <= id[w]; i++)
        printf("%c", s[i]);
    return 0;
}