#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 50;

vector<int> e[N];
queue<int> q;
int n, m, x, y, ans;
int in[N], ot[N], tot[N];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        e[x].push_back(y);
        in[y]++, ot[x]++;
    }
    for (int i = 1; i < n; i++)
        if (ot[i] && !in[i])
            tot[i] = 1, q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < e[t].size(); i++)
        {
            int to = e[t][i];
            tot[to] += tot[t], in[to]--;
            if (!in[to])
                q.push(to);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ot[i])
            ans += tot[i];
    cout << ans << endl;
    return 0;
}