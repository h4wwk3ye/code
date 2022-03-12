#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, mod = 1e9 + 7;
int dp[N];
int n, k;

int solve (int i) {
	if (i < 0) return 0;
	if (i == 0) return 1;
	int& ans = dp[i];
	if (ans != -1) return ans;

	ans = 0;
	for (int j = 2; j <= min (i, k); j += 2) {
		ans += solve (i - j);
		ans %= mod;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		fill (dp, dp + n + 4, -1);
		int ans = solve (n);
		cout << ans << '\n';
	}
	return 0;
}