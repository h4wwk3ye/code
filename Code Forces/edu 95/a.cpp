/*
				C++
				encoding: UTF-8
				Last Modified: 14/Sep/20 08:30:39 PM
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
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, k;
		cin >> x >> y >> k;
		// get k sticks and coal
		int reqStick = k + y * k;
		int trades = 0;
		if (reqStick > 1) {
			trades = 1;
			reqStick -= x;
			if (reqStick > 0) trades += ceil (reqStick / (x - 1) * 1.0);
		}
		// for coal
		trades += k;
		print (trades);
	}
	return 0;
}