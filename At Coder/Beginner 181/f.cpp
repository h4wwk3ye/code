/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 06:57:08 PM
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
	cout << fixed << setprecision (15);
	int n;
	cin >> n;
	vector< pair< int, int > > arr (n);
	for (auto& [x, y] : arr)
		cin >> x >> y;
	long double ans = 1e9;

	auto dist = [] (pair< int, int >& a, pair< int, int >& b) {
		return ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second));
	};

	if (n == 1) {
		print (max (abs (arr[0].second - 100), abs (arr[0].second + 100)));
		return 0;
	}

	for (auto i = 0; i < n; ++i) {
		long double mx1 = max (abs (arr[i].second - 100), abs (arr[i].second + 100));
		// now the point with least distance
		int idx = -1, d = 1e9;
		for (auto j = 0; j < n; ++j) {
			if (j == i) continue;
			long double mx2 = max (abs (arr[j].second - 100), abs (arr[j].second + 100));
			ans = min (ans, max ({mx1, mx2, static_cast< long double > (sqrt (dist (arr[i], arr[j])))}));
		}
	}
	print (ans / 2);
	return 0;
}