/*
				C++
				encoding: UTF-8
				Last Modified: 11/Aug/20 06:14:21 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

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
	int n, m;
	cin >> n >> m;
	vector< pair< int, int > > a (n), b (m);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = {x, i};
	}

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		b[i] = {x, i};
	}

	sort (a.begin (), a.end ());
	sort (b.begin (), b.end ());

	for (int i = 1; i < n; ++i) {
		print (a[i].second, b.back ().second);
	}
	for (int i = 0; i < m; ++i) {
		print (a[0].second, b[i].second);
	}
	return 0;
}