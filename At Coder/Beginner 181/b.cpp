/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 05:33:20 PM
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
	int n;
	cin >> n;
	int ans = 0;
	for (auto i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ans += ((b * (b + 1)) / 2) - ((a * (a - 1)) / 2);
	}
	print (ans);
	return 0;
}