/*
				C++
				encoding: UTF-8
				Last Modified: 30/Sep/20 09:44:13 PM
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
		int n, k;
		cin >> n >> k;
		vector< int > arr;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (!arr.size () or arr.back () != x) arr.push_back (x);
		}
		n = arr.size ();

		int ans = -1;
		for (int i = 1; i <= n; ++i) {
			int req = ceil ((n - 1) / (i * 1.0)) + 1;
			if (req <= k) {
				ans = i;
				break;
			}
		}
		print (ans);
	}
	return 0;
}