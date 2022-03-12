/*
				C++
				encoding: UTF-8
				Last Modified: 08/Nov/20 05:38:08 PM
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
	int ans = 2, mx = 0;
	for (int i = 2; i <= 1000; ++i) {
		int curr = 0;
		for (auto& j : arr) {
			if (j % i == 0) curr++;
		}
		if (curr > mx) {
			mx = curr;
			ans = i;
		}
	}
	print (ans);
	return 0;
}