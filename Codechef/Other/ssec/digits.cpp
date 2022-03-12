/*
				C++
				encoding: UTF-8
				Last Modified: 15/Sep/20 11:10:36 AM
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

	int curr = 0, mx = 0, l = 0, r = 0;
	int p = -1, cl = 0;

	for (int i = 0; i < s.size (); ++i) {
		int x = s[i] - '0';
		if (x > p) {
			curr += x;
		} else {
			cl = i;
			curr = x;
		}
		if (curr > mx) {
			mx = curr;
			l = cl;
			r = i;
		}
		p = x;
	}
	cout << mx << ':' << l + 1 << '-' << r + 1 << '\n';

	return 0;
}