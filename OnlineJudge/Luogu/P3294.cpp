#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 6e5 + 10;
int n;
char s[M];
struct node
{
    int c[26], tag;
} a[M];
int rot, tot;
inline void init() { rot = ++tot, a[rot].tag = 1; }
inline void ins(char *s)
{
    int pos = rot, val;
    for (; *s; s++)
    {
        val = *s - 'a';
        if (!a[pos].c[val])
            a[pos].c[val] = ++tot;
        pos = a[pos].c[val];
    }
    a[pos].tag = 1;
}
int cnt;
struct edge
{
    int to, nx;
    inline void init(int t, int n) { to = t, nx = n; }
} e[N];
int hd[N], c = 1, siz[N];
inline void adde(int u, int v)
{
    e[++c].init(v, hd[u]);
    hd[u] = c;
}
inline void trv(int pos, int pnt)
{
    if (a[pos].tag)
    {
        int npos = ++cnt;
        adde(pnt, npos), siz[npos] = 1;
        for (int i = 0; i < 26; i++)
            if (a[pos].c[i])
                trv(a[pos].c[i], npos);
        siz[pnt] += siz[npos];
    }
    else
    {
        for (int i = 0; i < 26; i++)
            if (a[pos].c[i])
                trv(a[pos].c[i], pnt);
    }
}
long long ans;
int buf[N], top;
inline void dfs(int pos)
{
    top = 0;
    for (int i = hd[pos]; i; i = e[i].nx)
        buf[top++] = siz[e[i].to];
    sort(buf, buf + top);
    int sum = 0;
    for (int i = 0; i < top; i++)
        ans += sum + 1, sum += buf[i];
    for (int i = hd[pos]; i; i = e[i].nx)
        dfs(e[i].to);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
        cin >> s, reverse(s, s + strlen(s)), ins(s);
    trv(rot, 0);
    dfs(1);
    cout << ans << endl;
    return 0;
}