#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, a[6];
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        bool f = false;
        for (int i = 1; i <= 4; i++)
            cin >> a[i];
        int p[] = {1, 2, 3, 4, 5};
        do
        {
            for (int i = 0; i <= 9; i++)
            {
                a[5] = i;
                if (a[p[0]] - 1 == a[p[1]] && a[p[1]] == a[p[2]] + 1 && a[p[3]] == a[p[4]])
                    f = true;
            }
        } while (next_permutation(p, p + 5));
        cout << (f ? 1 : 0) << endl;
    }
    return 0;
}