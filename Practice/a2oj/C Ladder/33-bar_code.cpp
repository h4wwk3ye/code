/*
				C++
				encoding: UTF-8
				Last Modified: 26/Sep/20 08:14:39 PM
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

int n, m, x, y;
const int N = 1e3 + 5;
char arr[N][N];
int dp[N][2], pref[N]; // 0 white, 1 black

int solve (int i, int c) {
	if (i == m) return 0;
	if (i > m) return 1e9;
	int& ans = dp[i][c];
	if (ans != -1) return ans;

	// paint next x to y colums by current color
	ans = 1e9;

	for (int j = x; j <= y; ++j) {
		ans = min (ans, solve (i + j, !c) + (c ? j * n - (pref[i + j] - pref[i]) : pref[i + j] - pref[i]));
	}
	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == '.') pref[j + 1]++;
		}
	}
	for (int j = 2; j <= m; ++j)
		pref[j] += pref[j - 1]; // prefix sum of white cells
	memset (dp, -1, sizeof dp);

	int ans = min (solve (0, 0), solve (0, 1));
	print (ans);
	return 0;
}