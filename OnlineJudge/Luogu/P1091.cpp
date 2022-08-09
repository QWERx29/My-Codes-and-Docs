#include <bits/stdc++.h>
using namespace std;
struct node
{
    int h, l, r;
} s[250];
int n, k;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i].h;
    for (int i = 1; i <= n; i++)
    {
        s[i].l = 1;
        for (int j = 1; j <= i - 1; j++)
            if (s[i].h > s[j].h && s[j].l + 1 > s[i].l)
                s[i].l = s[j].l + 1;
    }
    for (int i = n; i >= 1; i--)
    {
        s[i].r = 1;
        for (int j = i + 1; j <= n; j++)
            if (s[j].h < s[i].h && s[j].r + 1 > s[i].r)
                s[i].r = s[j].r + 1;
    }
    for (int i = 1; i <= n; i++)
        k = max(k, s[i].l + s[i].r);
    cout << n - k + 1;
    return 0;
}