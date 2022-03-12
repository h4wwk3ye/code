/*
				C++
				encoding: UTF-8
				Last Modified: 25/Jul/20 02:36:58 PM
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
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; ++T) {
		cout << "Case #" << T << ":\n";

		int n;
		cin >> n;
		string s;
		cin >> s;
	}
	return 0;
}