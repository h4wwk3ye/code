/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 06:02:49 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

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
		int x = 0;
		while (n) {
			int r = n % 10;
			x = x * 10 + r;
			n /= 10;
		}
		print (x);
	}
	return 0;
}