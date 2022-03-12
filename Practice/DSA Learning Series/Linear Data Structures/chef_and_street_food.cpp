/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 08:06:04 PM
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
		vector< int > s (n), v (n), p (n);
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			cin >> s[i] >> p[i] >> v[i];
			ans = max (ans, p[i] / (s[i] + 1) * v[i]);
		}
		print (ans);
	}
	return 0;
}