#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, w, x, y;
int weight[N], nutrition[N];
int dp[N][N][2][2];

int solve (int i, int j, int a, int b) { // index, weight, whether or not x and y are used
	if (i == n + 1) {
		return 0;
	}
	int& ans = dp[i][j][a][b];
	if (ans != -1) return ans;
	ans = 0;
	if (j < weight[i]) {
		ans = solve (i + 1, j, a, b);
	} else {
		if (a & b) {
			ans = max ({solve (i + 1, j, a, b),
						solve (i + 1, j - weight[i], a, b) + nutrition[i],
						solve (i + 1, j - weight[i], 0, b) + (nutrition[i] * x),
						solve (i + 1, j - weight[i], a, 0) + (nutrition[i] * y)});
		} else if (a) {
			ans = max ({solve (i + 1, j, a, b),
						solve (i + 1, j - weight[i], a, b) + nutrition[i],
						solve (i + 1, j - weight[i], 0, b) + (nutrition[i] * x)});
		} else if (b) {
			ans = max ({solve (i + 1, j, a, b),
						solve (i + 1, j - weight[i], a, b) + nutrition[i],
						solve (i + 1, j - weight[i], a, 0) + (nutrition[i] * y)});
		} else {
			ans = max (solve (i + 1, j, a, b), solve (i + 1, j - weight[i], a, b) + nutrition[i]);
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> w >> x >> y;
		for (int i = 1; i <= n; ++i) {
			cin >> weight[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> nutrition[i];
		}
		memset (dp, -1, sizeof dp);
		int ans = solve (1, w, 1, 1);
		cout << ans << '\n';
	}
	return 0;
}