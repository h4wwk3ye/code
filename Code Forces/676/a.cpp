/*
				C++
				encoding: UTF-8
				Last Modified: 18/Oct/20 02:44:22 PM
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
		int a, b;
		cin >> a >> b;
		string s;

		for (int i = 34; i >= 0; --i) {
			int x = (a >> i) & 1;
			int y = (b >> i) & 1;
			if (!x and !y) {
				s += '0';
			} else if ((x and !y) or (!x and y)) {
				s += '0';
			} else {
				s += '1';
			}
		}
		int ans = stoll (s, nullptr, 2);
		print ((ans ^ a) + (ans ^ b));
	}
	return 0;
}