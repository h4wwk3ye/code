/*
				C++
				encoding: UTF-8
				Last Modified: 04/Sep/20 10:06:43 PM
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
		int n, k;
		cin >> n >> k;
		vector< int > arr (n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 0; i < n; ++i) {
			int _;
			cin >> _;
		}

		sort (arr.begin (), arr.end ());

		int ans (0), l (0), r (0);
		vector< int > mx (n);
		for (int i = 0; i < n; ++i) {
			int j = lower_bound (arr.begin (), arr.end (), arr[i] + k + 1) - arr.begin ();
			mx[i] = j - i;
		}
		vector< int > mx2 (n);
		int m = 0;
		for (int i = n - 1; i >= 0; --i) {
			mx2[i] = m;
			m = max (m, mx[i]);
		}
		// print (mx, mx2);

		for (int i = 0; i < n; ++i) {
			ans = max (ans, min (mx[i] + mx2[i], n));
		}
		print (ans);
	}
	return 0;
}