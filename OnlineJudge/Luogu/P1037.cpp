#include <bits/stdc++.h>
using namespace std;
string str;
int s[33], num[33], nxt[33][20], q, k;
bool vis[15];
int ans[33];

inline void dfs(int x, int y)
{
    vis[x] = 1;
    if (vis[y])
        return;
    q++;
    for (int i = 1; i <= num[y]; i++)
        dfs(y, nxt[y][i]);
}
inline void mul()
{
    int w = 0;
    for (int i = 30; i; i--)
    {
        ans[i] = ans[i] * q + w;
        w = ans[i] / 10;
        ans[i] %= 10;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ans[30] = 1;
    cin >> str >> k;
    int l = str.size();
    for (int i = 0; i < l; i++)
        s[i + 1] = str[i] - '0';
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        nxt[x][++num[x]] = y;
    }
    for (int i = 1; i <= l; i++)
    {
        q = 1;
        for (int j = 1; j <= num[s[i]]; j++)
            dfs(s[i], nxt[s[i]][j]);
        memset(vis, 0, sizeof(vis));
        mul();
    }
    int r = 0;
    for (; ans[r] == 0; r++)
        ;
    for (int i = r; i <= 30; i++)
        cout << ans[i];
    return 0;
}