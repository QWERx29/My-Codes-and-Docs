#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 30;
int n;
int a[N], ans[N];
stack<int> s;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        ans[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}