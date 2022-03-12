/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/20 07:00:29 PM
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

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (auto& i : arr)
			cin >> i;
		sort (arr, arr + n);

		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			if (i + k > n) break;
			ans = min (ans, arr[i + k - 1] - arr[i]);
		}
		print (ans);
	}
	return 0;
}