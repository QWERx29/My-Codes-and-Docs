#include <bits/stdc++.h>
#define int long long

// using namespace std;
template <class T>
inline void read(T &x)
{
	x = 0;
	register char c = getchar(), d = 0;
	while (c < '0' || c > '9')
		d = c, c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + c - '0', c = getchar();
	if (d == '-')
		x = -x;
}
template <class T>
void wt(const T &x)
{
	if (x / 10)
		wt(x / 10);
	putchar(x % 10 + '0');
}
template <class T>
inline void wtsp(T x)
{
	if (x < 0)
		putchar('-'), x = -x;
	wt(x), putchar(' ');
}
template <class T>
inline void wtln(T x)
{
	if (x < 0)
		putchar('-'), x = -x;
	wt(x), putchar('\n');
}
template <class T>
inline const T &max(const T &x, const T &y) { return x < y ? y : x; }
template <class T>
inline const T &min(const T &x, const T &y) { return x < y ? x : y; }

const int N = 3080;

int n, m;
int h[N], l[N], r[N], ans;
int stk[N], top;
char mp[N][N];

inline char get()
{
	register char c = getchar();
	while (c != 'F' && c != 'R')
		c = getchar();
	return c;
}

signed main()
{
	//	ios::sync_with_stdio(false);
	//	cin.tie(0),cout.tie(0);
	//	cin>>n>>m;
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mp[i][j] = get();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			h[j] = mp[i][j] == 'F' ? h[j] + 1 : 0;
		stk[top = 0] = 0;
		for (int j = 1; j <= m; j++)
		{
			while (top && h[j] <= h[stk[top]])
				--top;
			l[j] = stk[top];
			stk[++top] = j;
		}
		stk[top = 0] = m + 1;
		for (int j = m; j >= 1; j--)
		{
			while (top && h[j] <= h[stk[top]])
				--top;
			r[j] = stk[top];
			stk[++top] = j;
		}
		for (int j = 1; j <= m; j++)
			ans = max(ans, h[j] * (r[j] - l[j] - 1));
	}
	//	ans*=3;
	wtln(ans);
	// cout<<ans<<endl;
	return 0;
}