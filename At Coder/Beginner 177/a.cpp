/*
				C++
				encoding: UTF-8
				Last Modified: 29/Aug/20 05:31:22 PM
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
	int d, t, s;
	cin >> d >> t >> s;
	if (t * s >= d) {
		print ("Yes");
	} else {
		print ("No");
	}
	return 0;
}