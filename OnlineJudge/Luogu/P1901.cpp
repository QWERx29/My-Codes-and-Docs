#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 30;
int n, x;
int h[N], v[N], ans[N];
stack<int> s;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && h[s.top()] < h[i])
            ans[i] += v[s.top()], s.pop();
        if (!s.empty())
            ans[s.top()] += v[i];
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        x = max(x, ans[i]);
    cout << x << "\n";
    return 0;
}