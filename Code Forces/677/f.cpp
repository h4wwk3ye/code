/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 09:38:11 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

const int N = 75;
int arr[N][N];

// unordered_map< string, int > mp;

int dp[N][N][N / 2][N];
int n, m, k;

int solve (int row, int col, int cnt, int sum) {
	if (cnt > m / 2 or col >= m) return solve (row + 1, 0, 0, sum);
	if (row >= n) return sum % k ? -1e18 : 0;

	int& ans = dp[row][col][cnt][sum];
	if (ans != -1) return ans;

	if (cnt == m / 2) {
		ans = solve (row + 1, 0, 0, sum);
	} else {
		ans = max ({solve (row + 1, 0, 0, sum),
					solve (row + 1, 0, 0, (sum + arr[row][col]) % k) + arr[row][col],
					solve (row, col + 1, cnt, sum),
					solve (row, col + 1, cnt + 1, (sum + arr[row][col]) % k) + arr[row][col]});
	}
	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> k;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	memset (dp, -1, sizeof dp);
	int ans = solve (0, 0, 0, 0);
	print (ans);
	return 0;
}