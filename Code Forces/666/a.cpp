/*
				C++
				encoding: UTF-8
				Last Modified: 01/Sep/20 02:34:01 PM
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
		vector< int > cnt (26, 0);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (auto j : s) {
				cnt[j - 'a']++;
			}
		}

		bool flag = true;
		for (auto& i : cnt) {
			if (i % n) {
				flag = 0;
				break;
			}
		}

		print (flag ? "YES" : "NO");
	}
	return 0;
}