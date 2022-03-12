/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/20 06:08:41 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;
		int s = (a + b) % 3;

		for (int i = 0; i < n - 2; ++i) {
			print ("Here");
			int t = b;
			b = (a + b) % 10;
			a = t;
			s += b;
			s %= 3;
		}
		print (s ? "NO" : "YES");
	}
	return 0;
}