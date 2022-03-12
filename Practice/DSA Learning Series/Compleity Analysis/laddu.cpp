/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/20 05:17:20 PM
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

		int cnt = 0;

		for (int i = 0; i < n; ++i) {
			string t;
			cin >> t;
			if (t == "CONTEST_WON") {
				int rank;
				cin >> rank;
				cnt += 300;
				if (rank < 20) cnt += 20 - rank;

			} else if (t == "TOP_CONTRIBUTOR") {
				cnt += 300;
			} else if (t == "BUG_FOUND") {
				int severity;
				cin >> severity;
				cnt += severity;
			} else {
				cnt += 50;
			}
		}
		print (s == "INDIAN" ? (cnt / 200) : (cnt / 400));
	}

	return 0;
}