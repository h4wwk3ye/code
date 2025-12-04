/*
				C++
				encoding: UTF-8
				Last Modified: 02/Jul/23 02:12:54 PM
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
		string s;
		n = 10;
		set< int > ans;
		for (int i = 0; i < n - 1; ++i) {
			ans.insert (1);
		}
		print (ans.size ());
	}
	return 0;
}