/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jun/20 11:04:15 AM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, n;
		cin >> a >> b >> n;
		int ans = 0;
		while (a <= n and b <= n) {
			if (a < b) {
				a += b;
			} else {
				b += a;
			}
			ans++;
		}
		print (ans);
	}
	return 0;
}