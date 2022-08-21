#include <bits/stdc++.h>
using namespace std;
int n;
double tab[13][13], ans[13], tmp[13];
inline void swp(int x, int y)
{
    for (int i = 1; i <= n + 1; i++)
        tmp[i] = tab[x][i];
    for (int i = 1; i <= n + 1; i++)
        tab[x][i] = tab[y][i];
    for (int i = 1; i <= n + 1; i++)
        tab[y][i] = tmp[i];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n, n++;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cin >> tab[i][j], tab[i][n + 1] += tab[i][j] * tab[i][j], tab[i][j] *= 2.0;
        tab[i][n] = 1.0;
    }
    int pos;
    double div;
    for (int i = 1; i <= n; i++)
    {
        pos = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(tab[pos][i]) < fabs(tab[j][i]))
                pos = j;
        if (pos != i)
            swp(pos, i);
        div = tab[i][i];
        for (int j = i; j <= n + 1; j++)
            tab[i][j] /= div;
        for (int j = i + 1; j <= n; j++)
        {
            div = tab[j][i];
            for (int k = i; k <= n + 1; k++)
                tab[j][k] -= tab[i][k] * div;
        }
    }
    ans[n] = tab[n][n + 1];
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = tab[i][n + 1];
        for (int j = i + 1; j <= n; j++)
            ans[i] -= tab[i][j] * ans[j];
    }
    for (int i = 1; i < n; i++)
        cout << fixed << setprecision(3) << ans[i] << " ";
    cout << "\n";
    return 0;
}