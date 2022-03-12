/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/20 08:39:52 PM
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
		string s;
		cin >> s;
		int ans = 0;
		int n = s.size ();
		if (n == 1) {
			print (1);
			continue;
		}
		stack< int > a, b;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A') {
				a.push (i);
			} else {
				if (!a.empty ()) {
					ans += 2;
					a.pop ();
				} else if (!b.empty ()) {
					ans += 2;
					b.pop ();
				} else {
					b.push (i);
				}
			}
		}
		print (n - ans);
	}
	return 0;
}