/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 07:02:16 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

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
		int g;
		cin >> g;
		while (g--) {
			int i, n, q;
			cin >> i >> n >> q;

			if (n & 1) {
				// other one will be 1 more than initial sate
				if (i == q) { // head
					print (n / 2);
				} else {
					print (n / 2 + 1);
				}
			} else {
				print (n / 2);
			}
		}
	}
	return 0;
}