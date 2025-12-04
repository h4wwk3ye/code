/*
				C++
				encoding: UTF-8
				Last Modified: 01/Jun/24 10:12:12 PM
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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b) swap (a, b);
		if (c > d) swap (c, d);

		if (a < c and c < b and b < d) {
			print ("YES");
		} else if (c < a and a < d and d < b) {
			print ("YES");
		} else {
			print ("NO");
		}
	}
	return 0;
}