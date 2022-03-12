/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/20 09:54:15 PM
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
		vector< int > arr (n);
		for (auto& i : arr)
			cin >> i;
		vector< int > mn1 (n), mn2 (n);
		mn1[0] = arr[0];
		for (auto i = 1; i < n; ++i)
			mn1[i] = min (mn1[i - 1], arr[i]);
		mn2.back () = arr.back ();
		for (auto i = n - 2; i >= 0; --i)
			mn2[i] = min (mn2[i + 1], arr[i]);

		int left = 0, right = 0;
		bool ans = true;
		int req = 0;
		int mn = arr[0];
		for (auto i = 1; i < n - 1; ++i) {
			if (arr[i] < req) {
				ans = false;
				break;
			}
			if (arr[i] > mn + mn2[i + 1]) {
				ans = false;
				break;
			}
			mn = min (mn, arr[i] - req);
			req = max (req, arr[i] - mn);
			// print (i, arr[i], req, mn);
		}
		print (ans ? "YES" : "NO");
	}
	return 0;
}