/*
				C++
				encoding: UTF-8
				Last Modified: 04/Oct/20 09:59:06 PM
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
		int n, m;
		cin >> n >> m;
		int arr[n][m];
		for (auto& i : arr)
			for (auto& j : i)
				cin >> j;

		int p = n / 2, q = m / 2;
		int ans = 0;
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < q; ++j) {
				vector< int > x = {arr[i][j], arr[i][m - j - 1], arr[n - i - 1][j], arr[n - i - 1][m - j - 1]};

				sort (x.begin (), x.end ());
				int a = 0, b = 0;
				for (int k = 0; k < 4; ++k) {
					a += abs (x[k] - x[1]);
					b += abs (x[k] - x[2]);
				}
				ans += min (a, b);
			}
		}

		// middle row and middle column
		if (n & 1) {
			int i = n / 2;
			for (int j = 0; j < m / 2; ++j) {
				ans += abs (arr[i][j] - arr[i][m - j - 1]);
			}
		}
		if (m & 1) {
			int j = m / 2;
			for (int i = 0; i < n / 2; ++i) {
				ans += abs (arr[i][j] - arr[n - i - 1][j]);
			}
		}
		print (ans);
	}
	return 0;
}