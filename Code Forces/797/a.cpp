/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jun/22 08:22:11 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
		int x = n / 3;
		int y = n % 3;
		print ((x + ((y == 2) ? 1 : 0)), (x + 1 + (y == 1 or y == 2 ? 1 : 0)), x - 1);
	}
	return 0;
}