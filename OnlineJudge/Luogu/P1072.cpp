#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1145141;

inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline int lcm(int x, int y) { return x * y / gcd(x, y); }

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a0, a1, b0, b1, cnt = 0;
        cin >> a0 >> a1 >> b0 >> b1;
        for (int i = 1; i * i <= b1; i++)
        {
            if (b1 % i != 0)
                continue;
            if (gcd(i, a0) == a1 && lcm(i, b0) == b1)
                cnt++;
            if (i * i == b1)
                break;
            int j = b1 / i;
            if (gcd(j, a0) == a1 && lcm(j, b0) == b1)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}