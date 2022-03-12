/*
				C++
				encoding: UTF-8
				Last Modified: 11/Aug/20 05:25:08 PM
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
		int n;
		cin >> n;
		vector< int > s (n);
		for (auto& i : s)
			cin >> i;

		vector< int > mn (n);
		int m = 1e9;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			m = min (m, s[i]);
			mn[i] = m;
			ans += mn[i];
		}
		print (ans);
	}
	return 0;
}