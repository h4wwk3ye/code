/*
				C++
				encoding: UTF-8
				Last Modified: 16/Jun/20 08:09:56 PM
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
		int arr[n];
		int e = 0, o = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (i & 1) {
				if (!(arr[i] & 1)) o++;
			} else {
				if (arr[i] & 1) e++;
			}
		}
		if (e != o)
			print (-1);
		else {
			print (e);
		}
	}
	return 0;
}