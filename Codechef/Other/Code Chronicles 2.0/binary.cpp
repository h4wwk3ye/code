/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 08:53:57 PM
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
		string s;
		cin >> s;
		int n = s.size ();
		int ans = 0;
		if (s[0] != '0') {
			bool flag = 0;
			int i = 1;
			while (i < n) {
				if (s[i] == '1') {
					if (flag) break;
				} else {
					++ans;
					flag = 1;
				}
				++i;
			}
		}
		print (ans);
	}

	return 0;
}