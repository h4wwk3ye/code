/*
				C++
				encoding: UTF-8
				Last Modified: 20/Aug/20 10:34:33 AM
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
	int rev = 0, r;
	int n;
	cin >> n;
	while (n) {
		r = n % 10;
		rev = rev * 10 + r;
		n /= 10;
	}
	int ans = 0;
	bool f = 1;
	while (rev) {
		r = rev % 10;
		if (f) ans = ans * 10 + r;
		rev /= 10;
		f = !f;
	}
	print (ans);

	return 0;
}