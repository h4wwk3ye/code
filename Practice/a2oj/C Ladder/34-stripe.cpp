/*
				C++
				encoding: UTF-8
				Last Modified: 06/Oct/20 09:32:41 PM
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
	int t = 0;
	for (auto& i : arr) {
		cin >> i;
		t += i;
	}
	if (t & 1) {
		print (0);
		return 0;
	}
	int ans = 0, curr = 0;
	for (int i = 0; i < n - 1; ++i) {
		curr += arr[i];

		if (curr == t / 2) {
			ans++;
		}
	}
	print (ans);
	return 0;
}