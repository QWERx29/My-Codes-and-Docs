#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, x, y;

inline void exgcd(int a, int b)
{
    if (b == 0)
        x = 1, y = 0;
    else
    {
        exgcd(b, a % b);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - a / b * y1;
    }
}

signed main()
{
    cin >> a >> b;
    exgcd(a, b);
    cout << (x + b) % b;
    return 0;
}