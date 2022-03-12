/*
				C++
				encoding: UTF-8
				Last Modified: 22/Aug/20 05:37:30 PM
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
	int n;
	cin >> n;
	vector< int > arr (n);
	for (auto& i : arr)
		cin >> i;

	int ans = 0, curr = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] < curr) {
			ans += curr - arr[i];
		}
		curr = max (curr, arr[i]);
	}
	print (ans);
	return 0;
}