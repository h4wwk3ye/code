/*
				C++
				encoding: UTF-8
				Last Modified: 01/Jun/24 10:12:02 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
		string s;
		cin >> s;
		int cnt = 0;
		bool zero = false;
		if (s[0] == '0') zero = true;
		for (int i = 1; i < s.size (); ++i) {
			int j = i;
			while (s[j] == '0') {
				// this set needs to be moved
				++j;
			}
			if (i != j and !zero) {
				cnt++;
			}
			zero = false;
			if (i != j) i = j - 1;
		}
		print (cnt + 1);
	}
	return 0;
}