/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 08:24:19 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

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
		int arr[n];
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			mx = max (mx, arr[i]);
		}
		sort (arr, arr + n);
		int ans = 0;
		// try for all possible weights // 50 + 50 = 100 * 1000 = 1e5
		for (int i = 1; i <= 2 * mx; ++i) {
			int k = 0, l = n - 1;
			int curr = 0;
			while (k < l) {
				int x = arr[k] + arr[l];
				if (x == i) {
					curr++;
					k++;
					l--;
				} else if (x < i) {
					k++;
				} else {
					l--;
				}
			}
			ans = max (ans, curr);
		}
		print (ans);
	}
	return 0;
}