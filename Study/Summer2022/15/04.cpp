#include <bits/stdc++.h>
using namespace std;
const int N = 114514;
int n, f, a[N], s[N];
double l = N, r = 0;
bool check(double ave)
{
    double sum1 = s[f - 1] - (f - 1) * ave;
    for (int i = f; i <= n; i++)
    {
        double sum2 = s[i] - s[i - f] - f * ave;
        sum1 = sum1 + a[i] - ave;
        sum1 = max(sum1, sum2);
        if (sum1 > -1e-5)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (l > a[i])
            l = a[i];
        if (r < a[i])
            r = a[i];
        s[i] = s[i - 1] + a[i];
    }
    double mid;
    while (r - l >= 1e-5)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << int(r * 1000) << endl;
    return 0;
}
