/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jun/20 12:27:59 PM
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

	set< pair< int, int > > arr;
	arr.emplace (0, 0);
	int i = 1;
	while (i <= n) {
		arr.emplace (i, i);
		// boundary
		arr.emplace (i - 1, i);
		arr.emplace (i + 1, i);
		arr.emplace (i, i - 1);
		arr.emplace (i, i + 1);
		++i;
	}
	arr.emplace (i, i);
	print ((int)arr.size ());
	for (auto& [a, b] : arr)
		print (a, b);
	return 0;
}