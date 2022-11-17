/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/22 09:15:46 PM
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
	string t = "Timur";
	sort (t.begin (), t.end ());
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		sort (s.begin (), s.end ());
		print (s == t ? "YES" : "NO");
	}
	return 0;
}