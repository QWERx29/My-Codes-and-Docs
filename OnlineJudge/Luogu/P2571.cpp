#include <bits/stdc++.h>
using namespace std;
using db = double;
const int N = 11451;
struct pt
{
    db x, y;
    inline pt(){};
    inline pt(db _x, db _y) : x(_x), y(_y){};
    inline void init() { cin >> x >> y; }
    inline pt operator*(const db &r) const { return pt(x * r, y * r); }
    inline pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
    inline pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
    inline db operator*(const pt &p) const { return x * p.x + y * p.y; }
} A, B, C, D, E, F;
db p, q, r, ans;
const db EPS = 1e-10;
inline db len(const pt &x) { return sqrt(x * x); }
inline db dis(const pt &x, const pt &y) { return len(x - y); }
inline db slv1() { return dis(A, E) / p + dis(E, F) / r + dis(F, D) / q; }
inline db slv2()
{
    db res = 1e10, L = 0, R = 1, l, r, lans, rans;
    while (R - L > EPS)
    {
        l = (L * 2 + R) / 3, r = (L + R * 2) / 3;
        F = C * l + D * (1 - l), lans = slv1();
        F = C * r + D * (1 - r), rans = slv1();
        if (lans < rans)
            res = min(res, lans), R = r;
        else
            res = min(res, rans), L = l;
    }
    return res;
}
inline db slv3()
{
    db res = 1e10, L = 0, R = 1, l, r, lans, rans;
    while (R - L > EPS)
    {
        l = (L * 2 + R) / 3, r = (L + R * 2) / 3;
        E = A * l + B * (1 - l), lans = slv2();
        E = A * r + B * (1 - r), rans = slv2();
        if (lans < rans)
            res = min(res, lans), R = r;
        else
            res = min(res, rans), L = l;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    A.init(), B.init(), C.init(), D.init();
    cin >> p >> q >> r;
    cout << fixed << setprecision(2) << slv3() << endl;
    return 0;
}