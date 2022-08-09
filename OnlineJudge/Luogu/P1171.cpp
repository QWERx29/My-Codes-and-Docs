#include <bits/stdc++.h>
//#define int unsigned long long
using namespace std;
int n, ans = 1145141919;
int a[20][20], f[1 << 20][20];

template <class T>
void read(T &x)
{
    x = 0;
    char c, d = '0';
    c = getchar();
    while (c < '0' || c > '9')
        d = c, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + c - '0', c = getchar();
    if (d == '-')
        x = -x;
}
template <class T>
void wt(T x)
{
    if (x / 10)
        wt(x / 10);
    putchar(x % 10 + '0');
}
template <class T>
void write(T x)
{
    if (x < 0)
        x = -x, putchar('-');
    wt(x), putchar('\n');
}

signed main()
{
    read(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            read(a[i][j]);
    memset(f, 63, sizeof(f));
    f[1][0] = 0;
    for (register int s = 0; s < (1 << n); s++)
        for (register int i = 0; i < n; i++)
            if ((s >> i) & 1)
                for (register int j = 0; j < n; j++)
                    if (!((s >> j) & 1))
                        if (f[s | (1 << j)][j] > f[s][i] + a[i][j])
                            f[s | (1 << j)][j] = f[s][i] + a[i][j];
    for (register int i = 0; i < n; i++)
        if (ans > f[(1 << n) - 1][i] + a[i][0])
            ans = f[(1 << n) - 1][i] + a[i][0];
    write(ans);
    return 0;
}