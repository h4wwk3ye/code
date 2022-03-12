/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 10:59:05 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>	 // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define int int64_t

typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		ordered_set left, right;

		vector< int > cnt (n, 0);
		int l = 0, r = 0;

		for (int i = 0; i < n; ++i) {
			cnt[i] += r;
			if (s[i] == 'L')
				l++;
			else
				r++;
		}
		l = 0;
		r = 0;

		for (int i = n - 1; i >= 0; --i) {
			cnt[i] += l;
			if (s[i] == 'L')
				l++;
			else
				r++;
		}
		auto cmp = [] (pair< int, int > a, pair< int, int > b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		};

		set< pair< int, int >, decltype (cmp) > se;
		for (int i = 0; i < n; ++i)
			se.insert ({cnt[i], i});

		// for maximum start from first
		int mx = 0;
		while (!se.empty ()) {
			auto [c, i] = *se.begin ();
			se.erase (se.begin ());

			mx += c; // respected by these many
			// remove r on left and l on right

			mx -= right.order_of_key (i);

			mx -= (left.size () - left.order_of_key (i)); // from total these many were on right;

			if (s[i] == 'L') {
				left.insert (i);
			} else {
				right.insert (i);
			}
		}

		//  similarly for minimum
		set< pair< int, int > > se1;
		for (int i = 0; i < n; ++i)
			se1.insert ({cnt[i], i});

		int mn = 0;
		left.clear ();
		right.clear ();
		while (!se1.empty ()) {
			auto [c, i] = *se1.begin ();
			se1.erase (se1.begin ());

			mn += c; // respected by these many
			// remove r on left and l on right

			mn -= right.order_of_key (i);

			mn -= (left.size () - left.order_of_key (i)); // from total these many were on right;

			if (s[i] == 'L') {
				left.insert (i);
			} else {
				right.insert (i);
			}
		}

		print (mx - mn, mx, mn);
	}
	return 0;
}