/*
				C++
				encoding: UTF-8
				Last Modified: 19/Sep/20 08:31:15 PM
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
	// nice staircases at 1, 3, 7, 15 ...
	vector< int > stairs;
	int curr, i = 1;
	int x = 0;
	while (x <= 2e18) {
		curr = pow (2, i) - 1;
		x = (curr * (curr + 1)) / 2;
		stairs.push_back (x);
		i++;
	}


	while (tc--) {
		int x;
		cin >> x;
		int ans = 0;
		int idx = 0;
		while (x > 0) {
			x -= stairs[idx++];
			if (x >= 0) ans++;
		}
		print (ans);
	}
	return 0;
}