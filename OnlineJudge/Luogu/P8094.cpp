#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 30;
int n, ans, a[N];
stack<int> s;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
            ans += i - s.top() + 1, s.pop();
        if (!s.empty())
            ans += i - s.top() + 1;
        s.push(i);
    }
    cout << ans << '\n';
    return 0;
}