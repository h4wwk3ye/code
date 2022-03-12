/*
				C++
				encoding: UTF-8
				Last Modified: 11/Aug/20 05:34:16 PM
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
		stack< char > stk;
		int ans = 0;
		for (int i = 0; i < s.size (); ++i) {
			if (s[i] == '<') {
				stk.push (s[i]);
			} else {
				if (stk.empty ()) {
					break;
				}
				stk.pop ();
				if (stk.empty ()) ans = i + 1;
			}
		}
		print (ans);
	}
	return 0;
}