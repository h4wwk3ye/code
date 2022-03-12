/*
				C++
				encoding: UTF-8
				Last Modified: 27/Sep/20 08:38:34 PM
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
		vector< int > arr (n);
		int mn = 1e9;
		int idx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (arr[i] < mn) {
				mn = arr[i];
				idx = i;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (idx == i) continue;
			int y = (k - arr[i]) / mn;
			ans += y;
		}
		print (ans);
	}
	return 0;
}