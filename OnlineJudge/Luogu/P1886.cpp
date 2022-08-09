#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 50;

int n, k, h[N];
int q[N], hd, tl;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    hd = 1, tl = 0;
    for (int i = 1; i < k; i++)
    {
        while (hd <= tl && h[i] <= h[q[tl]])
            --tl;
        q[++tl] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (hd <= tl && i - q[hd] >= k)
            ++hd;
        while (hd <= tl && h[i] <= h[q[tl]])
            --tl;
        q[++tl] = i;
        cout << h[q[hd]] << " ";
    }
    cout << endl;
    hd = 1, tl = 0;
    for (int i = 1; i < k; i++)
    {
        while (hd <= tl && h[i] >= h[q[tl]])
            --tl;
        q[++tl] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (hd <= tl && i - q[hd] >= k)
            ++hd;
        while (hd <= tl && h[i] >= h[q[tl]])
            --tl;
        q[++tl] = i;
        cout << h[q[hd]] << " ";
    }
    return 0;
}