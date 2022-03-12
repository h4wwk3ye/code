/*
				C++
				encoding: UTF-8
				Last Modified: 10/Oct/20 08:44:03 PM
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
		int arr[n];
		int s = 0;
		for (auto& i : arr) {
			cin >> i;
			s += i;
		}
		if (!s) {
			print ("NO");
			continue;
		}
		print ("YES");
		sort (arr, arr + n);
		if (s > 0) reverse (arr, arr + n);
		for (auto& i : arr)
			cout << i << ' ';

		cout << '\n';
	}
	return 0;
}