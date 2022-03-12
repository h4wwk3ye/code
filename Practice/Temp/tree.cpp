/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 02:00:41 PM
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
	int result = -404;
	int parent = 1, child = 2;
	while (true) {
		if (result != -404) break;
		for (int i = 0; i < parent; ++i) {
			child++;
			if (child >= n) {
				result = parent;
				break;
			}
		}
		parent++;
	}
	print (result);
	return 0;
}