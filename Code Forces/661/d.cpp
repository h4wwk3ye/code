/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 08:51:42 PM
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
		int ans = 0;

		vector< string > o;
		vector< int > zero, one;

		for (auto& i : s) {
			if (i == '0') {
				if (!one.size ()) {
					++ans;
					o.push_back (to_string (ans));
					zero.push_back (ans);
				} else { // add it to the last one and add it to zero
					int x = one.back ();
					one.pop_back ();
					o.push_back (to_string (x));
					zero.push_back (x);
				}
			} else {
				if (!zero.size ()) {
					++ans;
					o.push_back (to_string (ans));
					one.push_back (ans);
				} else {
					int x = zero.back ();
					zero.pop_back ();
					o.push_back (to_string (x));
					one.push_back (x);
				}
			}
		}
		print (ans);
		for (auto& i : o)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}