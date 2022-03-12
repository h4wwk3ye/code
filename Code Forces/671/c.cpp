/*
				C++
				encoding: UTF-8
				Last Modified: 19/Sep/20 09:34:11 PM
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
		int n, x;
		cin >> n >> x;
		vector< int > arr (n);

		bool same = 1;
		bool infected = 0;
		int cnt = 0;
		for (auto& i : arr) {
			cin >> i;
			if (i != x)
				same = 0;
			else
				infected = 1;

			cnt += i - x;
		}
		if (same) {
			print (0);
			continue;
		}
		if (infected) {
			print (1);
			continue;
		}

		print (cnt == 0 ? 1 : 2);
	}
	return 0;
}