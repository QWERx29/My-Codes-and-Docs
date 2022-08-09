#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll s, m;
        cin >> s >> m;
        if (m == 1 || (s & 1))
            cout << -1 << endl;
        else
            cout << 2 << " " << s / 2 << " " << s / 2 << endl;
    }
    return 0;
}