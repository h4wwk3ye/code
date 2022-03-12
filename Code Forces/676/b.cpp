/*
				C++
				encoding: UTF-8
				Last Modified: 18/Oct/20 03:59:41 PM
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
		int n;
		cin >> n;
		vector< string > arr (n);

		for (auto& i : arr)
			cin >> i;
		vector< pair< int, int > > ans;
		if (arr[0][1] == arr[1][0]) {
			if (arr[n - 1][n - 2] == arr[0][1]) {
				ans.push_back ({n - 1, n - 2});
			}
			if (arr[n - 2][n - 1] == arr[0][1]) {
				ans.push_back ({n - 2, n - 1});
			}
		} else {
			if (arr[n - 1][n - 2] == arr[n - 2][n - 1]) {
				// make the one at top different
				if (arr[0][1] == arr[n - 1][n - 2]) {
					ans.push_back ({0, 1});
				}
				if (arr[1][0] == arr[n - 1][n - 2]) {
					ans.push_back ({1, 0});
				}
			} else {
				// make top 0
				if (arr[0][1] != '0') {
					ans.push_back ({0, 1});
				}
				if (arr[1][0] != '0') {
					ans.push_back ({1, 0});
				}
				if (arr[n - 1][n - 2] != '1') {
					ans.push_back ({n - 1, n - 2});
				}
				if (arr[n - 2][n - 1] != '1') {
					ans.push_back ({n - 2, n - 1});
				}
			}
		}
		print (ans.size ());
		for (auto& [x, y] : ans)
			print (x + 1, y + 1);
	}
	return 0;
}