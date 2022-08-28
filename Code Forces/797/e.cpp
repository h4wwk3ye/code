/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jun/22 09:31:21 PM
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
		int n, k;
		cin >> n >> k;
		int arr[n];
		vector< multiset< int, greater< int > > > mod (k);

		for (auto& i : arr) {
			cin >> i;
			mod[i % k].insert (i);
		}
		int ans = 0;
		// first all pairs
		for (int i = 0; i <= k / 2; ++i) {
			if (i == 0) {
				while (mod[i].size () >= 2) {
					int x = *mod[i].begin ();
					mod[i].erase (mod[i].begin ());
					int y = *mod[i].begin ();
					mod[i].erase (mod[i].begin ());
					ans += (x + y) / k;
				}
			} else {
				int j = k - i;
				while (mod[i].size () and mod[j].size ()) {
					ans += (*mod[i].begin () + *mod[j].begin ()) / k;
					mod[i].erase (mod[i].begin ());
					mod[j].erase (mod[j].begin ());
				}
			}
		}
		vector< int > x;
		for (int i = 0; i <= k / 2; ++i) {
			while (mod[i].size ()) {
				x.push_back (*mod[i].begin ());
				mod[i].erase (mod[i].begin ());
			}
		}
		sort (x.begin (), x.end ());

		for (int i = 0; i < x.size () / 2; ++i) {
			ans += x[i] + x[x.size () - i - 1];
		}

		print (ans);
	}
	return 0;
}