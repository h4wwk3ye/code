/*
				C++
				encoding: UTF-8
				Last Modified: 13/Nov/20 08:17:48 PM
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
		int b[n], a[n], pref[n + 1];
		int p = 0;
		pref[0] = 0;
		for (auto i = 0; i < n; ++i) {
			cin >> b[i];
			a[i] = pow (2, b[i]);
			pref[i + 1] = p + a[i];
			p = pref[i + 1];
		}
		set< int > s;
		bool ans = true;
		for (auto i = 1; i <= n; ++i) {
			for (auto j = i; j <= n; ++j) {
				int sum = pref[j] - pref[i - 1];
				if (s.find (sum) != s.end ()) {
					ans = false;
					break;
				}
				s.insert (sum);
			}
			if (!ans) break;
		}
		print (ans ? "NO" : "YES");
	}
	return 0;
}