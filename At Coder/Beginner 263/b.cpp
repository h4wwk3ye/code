/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/22 05:39:04 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int arr[n + 1];
	map< int, int > parent;
	for (int i = 2; i <= n; ++i) {
		cin >> arr[i];
		parent[i] = arr[i];
	}
	// 0, 0, 1, 2
	int p = arr[n];
	int ans = 1;
	while (p != 1) {
		ans++;
		p = arr[p];
	}
	print (ans);
	return 0;
}