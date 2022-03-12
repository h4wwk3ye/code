/*
				C++
				encoding: UTF-8
				Last Modified: 31/Aug/20 04:21:37 PM
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
		vector< int > arr (n);
		int g = 0, p = 1;
		for (auto& i : arr) {
			cin >> i;
			g = __gcd (i, g);
			p *= i;
		}
		int r;
		cin >> r;
		int l = p / g;
		print (p + r);
	}
	return 0;
}