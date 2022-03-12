/*
				C++
				encoding: UTF-8
				Last Modified: 22/Aug/20 05:34:26 PM
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
	string s;
	cin >> s;
	int c = 0;
	for (auto i : s) {
		int x = i - '0';
		c += x % 9;
		c %= 9;
	}
	print (!c ? "Yes" : "No");
	return 0;
}