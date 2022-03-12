/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jun/20 12:55:28 PM
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
	int n;
	cin >> n;
	vector< int > arr (n);
	for (auto& i : arr)
		cin >> i;

	vector< int > bits (22, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 22; ++j) {
			if ((arr[i] >> j) & 1) bits[j]++;
		}
	}
	int ans = 0;
	int curr = (1 << 21) - 1;
	for (int i = 0; i < n; ++i) {
		int curr = 0;
		for (int bit = 21; bit >= 0; bit--) {
			if (i == bit) {
				curr |= (1 << bit);
			}
		}
	}
	print (ans);
	return 0;
}