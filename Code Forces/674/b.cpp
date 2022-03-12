/*
				C++
				encoding: UTF-8
				Last Modified: 28/Sep/20 01:48:32 PM
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
		int n, m;
		cin >> n >> m;
		vector< tuple< int, int, int, int > > arr (n);
		for (auto& [a, b, c, d] : arr)
			cin >> a >> b >> c >> d;

		if (m & 1) {
			print ("NO");
			continue;
		}

		// if transpose of a matrix is present
		bool ans = false;
		for (int i = 0; i < n; ++i) {
			auto& [a, b, c, d] = arr[i];
			if (b == c) ans = true;
		}
		print (ans ? "YES" : "NO");
	}
	return 0;
}