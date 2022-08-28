/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/22 05:33:00 PM
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
	map< int, int > s;
	for (int i = 0; i < 5; ++i) {
		int j;
		cin >> j;
		s[j]++;
	}
	int y = (s.begin ())->second;
	if (s.size () == 2 and (y == 2 or y == 3)) {
		print ("Yes");
	} else {
		print ("No");
	}

	return 0;
}