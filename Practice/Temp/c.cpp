/*
				C++
				encoding: UTF-8
				Last Modified: 08/Oct/20 09:37:37 PM
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
	int l, r, k, n;
	cin >> l >> r >> k >> n;
	string m;
	cin >> m;
	int ans = -1;
	for (int i = l; i <= r; ++i) {
		string s = bitset< 64 > (i).to_string ();
		if (s.find (m) != string::npos) {
			--k;
			if (!k) {
				ans = i;
				break;
			}
		}
	}
	print (ans);
	return 0;
}