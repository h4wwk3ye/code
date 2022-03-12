/*
				C++
				encoding: UTF-8
				Last Modified: 08/Nov/20 05:48:01 PM
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

int ans = 2e18;
string s;
void solve (int i, int sum, int cnt) {
	if (i == s.size ()) {
		if (sum % 3 == 0 and sum != 0) {
			ans = min (ans, cnt);
		}
		return;
	}

	solve (i + 1, sum + (s[i] - '0'), cnt);
	solve (i + 1, sum, cnt + 1);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> s;
	solve (0, 0, 0);
	print (ans == 2e18 ? -1 : ans);
	return 0;
}