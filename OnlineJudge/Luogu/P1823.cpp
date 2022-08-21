#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 50;
int n, x, ans;
stack<pii> s;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        pii p = {x, 1};
        while (!s.empty() && s.top().first <= x)
        {
            if (s.top().first == x)
                p.second += s.top().second;
            ans += s.top().second, s.pop();
        }
        if (!s.empty())
            ans++;
        s.push(p);
    }
    cout << ans << '\n';
    return 0;
}