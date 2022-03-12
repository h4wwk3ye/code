/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/20 08:46:53 PM
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
		cin >> s;
		int p = 0;
		bool z = 0;
		auto n = s.size ();
		int ans = 0;
		bool found = 0;
		for (auto i = 0; i < n; ++i) {
			if (s[i] == '1') {
				found = 1;
				if (z) {
					// join or blow the previous mine
					int x = (i - p - 1) * b;
					if (x < a) {
						// join
						ans += x;
					} else {
						ans += a;
					}
					p = i;
				} else {
					p = i;
					z = 0;
				}
			} else {
				if (found) z = 1;
			}
		}
		if (found) ans += a;
		print (ans);
	}
	return 0;
}