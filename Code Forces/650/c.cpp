/*
				C++
				encoding: UTF-8
				Last Modified: 16/Jun/20 08:25:44 PM
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = 0;
		set< int > se;

		for (int i = 0; i < s.size (); ++i) {
			if (s[i] == '1') se.insert (i);
		}

		for (int i = 0; i < s.size (); ++i) {
			if (s[i] == '0') {
				if (se.empty ()) {
					se.insert (i);
					ans++;
					continue;
				}
				auto it = se.lower_bound (i);
				if (it != se.begin ()) {
					--it;
				}
				if (*it < i and *it >= i - k) continue; // not possible

				it = se.upper_bound (i);
				if (it != se.end ()) {
					if (*it > i and *it <= i + k) continue;
				}
				ans++;
				se.insert (i);
			}
		}
		print (ans);
	}
	return 0;
}