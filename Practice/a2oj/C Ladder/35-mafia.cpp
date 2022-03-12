/*
				C++
				encoding: UTF-8
				Last Modified: 06/Oct/20 10:09:08 PM
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
	int sum = 0, mx = 0;
	int arr[n];
	for (auto& i : arr) {
		cin >> i;
		sum += i;
		mx = max (mx, i);
	}
	int ans = (sum + n - 2) / (n - 1);
	print (max (ans, mx));
	return 0;
}