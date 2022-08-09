// Queue D
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3080;

int n, a, b, ans;
int x[N][N], y[N][N], z[N][N];
int q[N], hd, tl;

signed main()
{
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> x[i][j];
    ans = 1145141919810;
    for (int j = 1; j <= b; j++)
    {
        hd = 1, tl = 0;
        for (int i = 1; i <= n; i++)
        {
            while (hd <= tl && x[i][j] <= x[q[tl]][j])
                --tl;
            q[++tl] = i;
        }
        for (int i = n; i <= a; i++)
        {
            while (hd <= tl && i - q[hd] >= n)
                ++hd;
            while (hd <= tl && x[i][j] <= x[q[tl]][j])
                --tl;
            q[++tl] = i;
            y[i - n + 1][j] = x[q[hd]][j];
        }
    }
    for (int i = 1; i <= a - n + 1; i++)
    {
        hd = 1, tl = 0;
        for (int j = 1; j < n; j++)
        {
            while (hd <= tl && y[i][j] <= y[i][q[tl]])
                --tl;
            q[++tl] = j;
        }
        for (int j = n; j <= b; j++)
        {
            while (hd <= tl && j - q[hd] >= n)
                ++hd;
            while (hd <= tl && y[i][j] <= y[i][q[tl]])
                --tl;
            q[++tl] = j;
            z[i][j - n + 1] = y[i][q[hd]];
        }
    }

    for (int j = 1; j <= b; j++)
    {
        hd = 1, tl = 0;
        for (int i = 1; i <= n; i++)
        {
            while (hd <= tl && x[i][j] >= x[q[tl]][j])
                --tl;
            q[++tl] = i;
        }
        for (int i = n; i <= a; i++)
        {
            while (hd <= tl && i - q[hd] >= n)
                ++hd;
            while (hd <= tl && x[i][j] >= x[q[tl]][j])
                --tl;
            q[++tl] = i;
            y[i - n + 1][j] = x[q[hd]][j];
        }
    }
    for (int i = 1; i <= a - n + 1; i++)
    {
        hd = 1, tl = 0;
        for (int j = 1; j < n; j++)
        {
            while (hd <= tl && y[i][j] >= y[i][q[tl]])
                --tl;
            q[++tl] = j;
        }
        for (int j = n; j <= b; j++)
        {
            while (hd <= tl && j - q[hd] >= n)
                ++hd;
            while (hd <= tl && y[i][j] >= y[i][q[tl]])
                --tl;
            q[++tl] = j;
            ans = min(ans, y[i][q[hd]] - z[i][j - n + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}