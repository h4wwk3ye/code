/*
				C++
				encoding: UTF-8
				Last Modified: 19/Sep/20 08:12:17 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (s.size () & 1) {
			// raze at end
			// if raze can leave atleast 1 odd
			bool f = 0;
			for (int i = 0; i < s.size (); i += 2) {
				int x = s[i] - '0';
				if (x & 1) {
					f = 1;
					break;
				}
			}
			print (f ? 1 : 2);
		} else {
			bool f = 0;
			for (int i = 1; i < s.size (); i += 2) {
				int x = s[i] - '0';
				if (!(x & 1)) {
					f = 1;
					break;
				}
			}
			print (f ? 2 : 1);
		}
	}
	return 0;
}