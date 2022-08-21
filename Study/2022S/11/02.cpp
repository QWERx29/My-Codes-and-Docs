#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 3e6 + 50;

int stk[N], cnt[N], top;
int n, h[N], ans;

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
	{
		while (top && h[i] > h[stk[top]])
			--top, ++ans;
		if (top && h[i] == h[stk[top]])
		{
			ans += cnt[top];
			if (cnt[top] < top)
				++ans;
			stk[++top] = i, cnt[top] = cnt[top - 1] + 1;
		}
		else
		{
			if (top)
				++ans;
			stk[++top] = i, cnt[top] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}