/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 08:20:21 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 2 * n;
		int a = 0, b = 0;
		int x = n, y = n;
		for (int i = 0; i < 2 * n; ++i) {
			if (i & 1) {
				if (s[i] == '1') {
					++b;
				}
				--y;
			} else {
				if (s[i] == '1') {
					++a;
				}
				--x;
			}

			// check if a can't win

			if (a - b > y) {
				ans = i + 1;
				break;
			}
			if (b - a > x) {
				ans = i + 1;
				break;
			}
		}
		print (ans);
	}
	return 0;
}