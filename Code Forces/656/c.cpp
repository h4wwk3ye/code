/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jul/20 09:00:39 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

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
		vector< int > arr (n);
		for (int& i : arr)
			cin >> i;

		vector< bool > flag (n, 0);

		vector< int > mx1 (n, 1e9), mx2 (n, 1e9);

		mx1[0] = arr[0];
		for (int i = 1; i < n; ++i) {
			mx1[i] = max (mx1[i - 1], arr[i]);
		}

		mx2.back () = arr.back ();
		for (int i = n - 2; i >= 0; --i) {
			mx2[i] = max (mx2[i + 1], arr[i]);
		}

		for (int i = 1; i < n - 1; ++i) {
			if (mx1[i] > arr[i] and mx2[i] > arr[i]) {
				flag[i] = 1;
			}
		}

		int ans = 0;
		for (int i = n - 2; i > 0; --i) {
			if (flag[i] and arr[i - 1] > arr[i]) {
				ans = i;
				break;
			}
		}
		print (ans);
	}
	return 0;
}