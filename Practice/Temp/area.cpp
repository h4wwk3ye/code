#include <bits/stdc++.h>
using namespace std;

const int N = static_cast< int > (1e5 + 5);
int arr[N], dp[N];
int n;

int solve (int idx) {
	if (idx >= n) return 0;
	int& ans = dp[idx];
	if (ans != -1) return ans;
	if (!idx or dp[idx - 1] != -1)
		ans = solve (idx + 2) + arr[idx];
	else
		ans = min (solve (idx + 2), solve (idx - 1)) + arr[idx];
	return ans;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	memset (dp, -1, sizeof dp);

	cout << solve (0) << '\n';
}
