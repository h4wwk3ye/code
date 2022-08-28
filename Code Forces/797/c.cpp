/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jun/22 08:37:25 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
		int s[n], f[n];
		for (auto& i : s)
			cin >> i;
		for (auto& i : f)
			cin >> i;
		int d[n];
		int t = 0;
		for (int i = 0; i < n; ++i) {
			int start = max (s[i], t);
			d[i] = f[i] - start;
			t = f[i];
		}
		for (auto& i : d)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}