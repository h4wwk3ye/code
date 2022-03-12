/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 08:07:38 PM
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
		sort (arr, arr + n);
		bool flag = 1;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i + 1] - arr[i] > 1) {
				flag = 0;
				break;
			}
		}
		print (flag ? "YES" : "NO");
	}
	return 0;
}