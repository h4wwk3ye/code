/*
				C++
				encoding: UTF-8
				Last Modified: 09/Oct/20 05:12:20 PM
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
		sort (a, a + n);
		sort (b, b + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += abs (a[i] - b[i]);
		}
		print (ans);
	}
	return 0;
}