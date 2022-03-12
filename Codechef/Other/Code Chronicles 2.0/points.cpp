/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 08:44:10 PM
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
		int n, m, c;
		cin >> n >> m >> c;
		int x1 = 0, y1 = c, x2 = 1, y2 = m + c;

		int l = 0, r = 0;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			int d = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
			if (d > 0) {
				++l;
			} else if (d < 0) {
				r++;
			}
		}
		print (r * l);
	}


	return 0;
}