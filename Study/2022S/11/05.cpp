#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 3e6 + 5;

int n, k, a[N], ans;
int stk[N], top;

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] = a[i - 1] + a[i] - k;
	stk[top = 1] = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= a[stk[top]])
			stk[++top] = i;
	for (int i = n; i > 1; i--)
	{
		if (a[i] >= a[stk[top]])
		{
			while (top > 1 && a[i] >= a[stk[top - 1]])
				--top;
			ans = max(ans, i - stk[top]);
		}
	}
	cout << ans << endl;
	return 0;
}