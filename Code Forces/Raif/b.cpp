/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/20 07:10:20 PM
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
		string s;
		cin >> s;
		int ans = 0;
		bool flag = 0;
		char c = '.';

		for (int i = 0; i < n; ++i) {
			if (s[i] == '-') continue;
			if (c == '.') c = s[i];
			if (s[i] != c) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			print (n);
			continue;
		}

		// all those that are connected by -
		set< int > mp;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '-') {
				mp.insert (i);
				mp.insert ((i + 1) % n);
			}
		}
		print (mp.size ());
	}
	return 0;
}