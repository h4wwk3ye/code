/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jul/20 08:31:28 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
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
		int x, y, z;
		cin >> x >> y >> z;
		vector< int > p = {x, y, z};
		sort (p.begin (), p.end ());

		if (p[1] == p[2] and p[0] <= p[1]) {
			print ("Yes");
			print (p[0], p[1], 1);
		} else {
			print ("No");
		}
	}
	return 0;
}