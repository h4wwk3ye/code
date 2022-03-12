/*
				C++
				encoding: UTF-8
				Last Modified: 01/Sep/20 12:40:59 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector< int > arr (n), luck (n), guide (m);
		for (auto& i : arr)
			cin >> i;
		for (auto& i : luck)
			cin >> i;
		for (auto& i : guide)
			cin >> i;

		vector< int > groups (m + 1, 0);
		for (auto& i : arr) {
			groups[i] += i;
		}
		int luck = 0;
		for (int i = 0; i < m; ++i) {
			groups[i + 1] %= guide[i];
		}
	}
	return 0;
}