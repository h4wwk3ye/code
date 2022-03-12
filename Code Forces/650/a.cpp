/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jun/20 02:10:36 PM
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
		string s;
		cin >> s;
		string a;
		a += s[0];
		a += s[1];
		for (int i = 3; i < s.size (); i += 2) {
			a += s[i];
		}
		print (a);
	}
	return 0;
}