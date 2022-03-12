/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/20 06:37:44 PM
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
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		print (abs (x2 - x1) + abs (y2 - y1) + (((x1 == x2) or (y1 == y2)) ? 0 : 2));
	}
	return 0;
}