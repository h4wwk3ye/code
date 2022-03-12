/*
				C++
				encoding: UTF-8
				Last Modified: 28/Sep/20 02:24:19 PM
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
		int n;
		cin >> n;
		bool f = false;
		int ans = 0, curr = 1, p = 1;
		while (curr < n) {
			if (!f) {
				curr += p;
			} else {
				curr += p + 1;
				p++;
			}
			ans++;
			f = !f;
		}
		print (ans);
	}
	return 0;
}