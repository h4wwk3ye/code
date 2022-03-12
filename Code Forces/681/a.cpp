/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/20 08:31:36 PM
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
		int n;
		cin >> n;
		if (n == 1) {
			print (2);
		} else if (n == 2) {
			print (4, 6);
		} else {
			// cout << 4 << ' ' << 6 << ' ';
			int p = 4 * n;
			set< int > s = {4 * n};

			for (int i = 0; i < n - 1; ++i) {
				bool flag = 0;
				for (auto& j : s) {
					if (p % j == 0 or __gcd (p, j) == 1) {
						flag = 1;
						break;
					}
				}
				if (flag)
					--i;
				else {
					s.insert (p);
				}
				p--;
			}
			for (auto& i : s)
				cout << i << ' ';
			cout << '\n';
		}
	}
	return 0;
}