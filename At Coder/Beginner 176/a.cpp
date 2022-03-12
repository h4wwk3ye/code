/*
				C++
				encoding: UTF-8
				Last Modified: 22/Aug/20 05:32:34 PM
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
	int n, x, t;
	cin >> n >> x >> t;
	int ans = ceil (n / (x * 1.0)) * t;
	print (ans);
	return 0;
}