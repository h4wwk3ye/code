/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jun/22 08:57:07 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector< int > cnt (n, 0);
		int p = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'B') {
				cnt[i] = p + 1;
			} else {
				cnt[i] = p;
			}
			p = cnt[i];
		}
		int ans = 1e9;
		for (int i = k - 1; i < n; ++i) {
			int x = cnt[i];
			if (i - k >= 0) x -= cnt[i - k];
			ans = min (ans, k - x);
			debug (i, x, ans);
		}
		debug (cnt);
		print (ans);
	}
	return 0;
}