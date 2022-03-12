/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 08:23:29 PM
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
		int arr[n];
		int mx = -1;
		for (auto& i : arr) {
			cin >> i;
			mx = max (mx, i);
		}
		int idx = -1;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == mx) {
				if (i - 1 >= 0) {
					if (arr[i - 1] < mx) {
						idx = i + 1;
						break;
					}
				}
				if (i + 1 < n) {
					if (arr[i + 1] < mx) {
						idx = i + 1;
						break;
					}
				}
			}
		}
		print (idx);
	}
	return 0;
}