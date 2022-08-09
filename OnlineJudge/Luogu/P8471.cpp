#include <bits/stdc++.h>
using namespace std;
int T, n, a, e, sa, sb, p, q;
char s[200010];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> a >> e >> (s + 1);
        sa = sb = 0;
        int l = n << 1;
        for (int i = 1; i <= l; i++)
        {
            if (s[i] == 'A')
                sa++;
            else
                sb++;
        }
        int sum = e - sa + a;
        if (sum & 1)
        {
            cout << -1 << endl;
            continue;
        }
        q = sum >> 1, p = (a - e + sa) >> 1;
        if (p < 0 || q < 0 || p > min(a, sa) || q > min(a, sb))
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= l;i++)
        {
            if(s[i]=='A')
            {
                if(p)
                    cout << "A", p--;
                else
                    cout << "B";
            }
            else
            {
                if(q)
                    cout << "A", q--;
                else
                    cout << "B";
            }
        }
        cout << "\n";
    }
    return 0;
}