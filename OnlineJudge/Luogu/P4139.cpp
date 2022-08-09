#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 11451419;

int p[N / 10], phi[N + 1], tot = 0, n, T;
bool v[N + 1];

inline void get_phi()
{
    phi[1] = 0;
    v[0] = v[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!v[i])
            p[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && p[j] * i <= N; j++)
        {
            int pri = p[j], ip = i * pri;
            v[ip] = 1;
            if (i % pri == 0)
            {
                phi[ip] = phi[i] * pri;
                break;
            }
            else
                phi[ip] = phi[i] * phi[pri];
        }
    }
}
inline int qpow(int x, int y, int mod)
{
    int q = x, res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * q % mod;
        q = q * q % mod;
    }
    return res;
}
inline int work(int x)
{
    if (x == 0)
        return 0;
    else
        return qpow(2, phi[x] + work(phi[x]), x);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    get_phi();
    while (T--)
    {
        cin >> n;
        cout << work(n) << endl;
    }
    return 0;
}