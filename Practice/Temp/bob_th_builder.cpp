/*
				C++
				encoding: UTF-8
				Last Modified: 23/Oct/20 12:51:43 PM
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

int n, h, w;
const int N = 3e3 + 5;
array< int, N > arr;
array< array< int, N >, N > dp;

int solve (int idx, int prv) {
	if (idx == n + 1) {
		return idx - prv <= w ? 0 : 1e9;
	}
	int& ans = dp[idx][prv];
	if (ans != -1) return ans;

	if (idx - prv < w) {
		ans = min (solve (idx + 1, idx) + arr[idx], solve (idx + 1, prv));
	} else {
		ans = solve (idx + 1, idx) + arr[idx];
	}
	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> h >> w;

	for (size_t i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	arr[0] = arr[n + 1] = 0;

	memset (&dp, -1, sizeof dp);

	print (solve (1, 0));

	return 0;
}