/*
				C++
				encoding: UTF-8
				Last Modified: 08/Nov/20 06:24:30 PM
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
	int n;
	cin >> n;
	int arr[n];
	for (auto& i : arr)
		cin >> i;

	int pref = 0, right = 0, curr = 0, prev = 0;
	int ans = 0;
	for (auto i = 0; i < n; ++i) {
		prev = curr;
		curr = curr + pref + arr[i];
		pref += arr[i];
		ans = max ({ans, curr, prev + right});
		if (i != n - 1) ans = max (ans, curr + right);
		right = max (right, curr - prev);
	}
	print (ans);
	return 0;
}