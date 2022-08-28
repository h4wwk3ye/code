/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jun/22 08:33:19 PM
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
		int n;
		cin >> n;
		int a[n], b[n];
		for (auto& i : a)
			cin >> i;
		for (auto& i : b)
			cin >> i;

		// difference between every positive pair should be same
		// and more than difference between every positive and zero pair

		int mxp = -1, mxz = -1;
		bool possible = true;
		set< int > s;
		for (int i = 0; i < n; ++i) {
			if (a[i] < b[i]) {
				possible = false;
				break;
			}
			if (b[i] == 0) {
				mxz = max (mxz, a[i] - b[i]);
			} else {
				mxp = max (mxp, a[i] - b[i]);
				s.insert (a[i] - b[i]);
			}
		}
		debug (s, mxp, mxz);
		if (s.size () > 1 or (mxp != -1 and mxp < mxz)) possible = false;
		print (possible ? "YES" : "NO");
	}
	return 0;
}