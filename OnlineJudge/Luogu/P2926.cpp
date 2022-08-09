#include <bits/stdc++.h>
using namespace std;
const int N = 1145141;

int a[N], b[N], ans[N];
int m, n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
        m = max(m, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!b[i])
            continue;
        for (int j = i; j <= m; j += i)
            ans[j] += b[i];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[a[i]] - 1 << endl;
    return 0;
}