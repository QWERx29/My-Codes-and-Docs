#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii> pq;
const int N = 3e5 + 15;
int n, m, ans;
int a[N], del[N], pre[N], nxt[N];
void remove(int x)
{
    del[x] = 1;
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
}
signed main()
{
    cin >> n >> m;
    if (n < m * 2)
        cout << "Error!", exit(0);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = i - 1, nxt[i] = i + 1, pq.push(pii(a[i], i));
    pre[1] = n, nxt[n] = 1;
    int cur;
    for (int i = 1; i <= m; i++)
    {
        do
            cur = pq.top().second, pq.pop();
        while (del[cur]);
        ans += a[cur];
        a[cur] = a[nxt[cur]] + a[pre[cur]] - a[cur];
        remove(pre[cur]), remove(nxt[cur]);
        pq.push(pii(a[cur], cur));
    }
    cout << ans;
    return 0;
}