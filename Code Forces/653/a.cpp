/*
				C++
				encoding: UTF-8
				Last Modified: 28/Jun/20 08:07:51 PM
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
		int x, y, n;
		cin >> x >> y >> n;
		int z = (n / x) * x;

		while (z + y > n) {
			z -= x;
		}
		print (z + y);
	}
	return 0;
}