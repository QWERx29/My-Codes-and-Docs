#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int n, m, x, y, z;
struct mat
{
    int d[N][N];
    inline mat()
    {
        memset(d, 0x3f, sizeof d);
        for (int i = 1; i < N; i++)
            d[i][i] = 0;
    }
    inline int *operator[](const int &i) { return d[i]; }
    inline const int *operator[](const int &i) const { return d[i]; }
    inline mat operator*(mat &q) const
    {
        mat w;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    w[i][j] = min(w[i][j], d[i][k] + q[k][j]);
        return w;
    }
    inline bool check()
    {
        for (int i = 1; i <= n; i++)
            if (d[i][i] < 0)
                return 1;
        return 0;
    }
}b[32],a,c;
int ans;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>x>>y>>z,b[0][x][y]=z;
    int t=0;
    while(t<10&&!b[t].check()) b[t+1]=b[t]*b[t],t++;
    if(!b[t].check()) cout<<"0\n",exit(0);
    while(t--)
    {
        c=a*b[t];
        if(!c.check())ans|=1<<t,a=c;
    }
    cout<<ans+1<<"\n";
    return 0;
}