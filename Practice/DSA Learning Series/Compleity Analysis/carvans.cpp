/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 06:35:47 PM
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
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int ans = 0;
		int curr_min = 1e10;
		for (int i = 0; i < n; ++i) {
			if (arr[i] <= curr_min) {
				++ans;
				curr_min = arr[i];
			}
		}
		print (ans);
	}
	return 0;
}