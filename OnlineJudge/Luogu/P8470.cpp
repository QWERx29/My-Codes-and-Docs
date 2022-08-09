#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
map<int, map<int, ll>> g;
unsigned long long ans;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        for (int j = 0; j < 4;j++)
        {
            int xx = x + dx[j], yy = y + dy[j];
            if(g[xx][yy]>g[x][y])
                ans -= 2ull * min(z, g[xx][yy] - g[x][y]);
        }
        g[x][y] += z;
        ans += 4ull * z;
        cout << ans << endl;
    }
    return 0;
}