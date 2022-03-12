/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 08:48:29 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		unordered_map< int, vector< int > > mp;
		mp.max_load_factor (0.25);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i - 1];
			mp[arr[i - 1]].push_back (i);
		}
		if (mp.size () == 1) {
			print ("NO");
			continue;
		}
		// need to build n - 1 roads
		vector< pair< int, int > > roads;
		set< int > done;
		int remaining = n - 1;
		auto it = mp.begin ();
		auto& [k, v] = *it;
		// need to consider v - 1 roads
		remaining -= (v.size () - 1);
		// one of them builds road by everyone else
		while (remaining) {
			for (auto& [p, q] : mp) {
				if (p == k) continue;
				for (auto& j : q) {
					if (!remaining) break;
					roads.push_back ({v[0], j});
					remaining--;
					done.insert (p);
					done.insert (k);
				}
			}
		}
		// now connect all the roads of first index

		++it;
		int j = it->second[0];

		for (int i = 1; i < v.size (); ++i) {
			roads.push_back ({v[i], j});
			done.insert (it->first);
			done.insert (k);
		}

		if (done.size () != mp.size ()) {
			print ("NO");
			continue;
		}

		print ("YES");
		for (auto& [a, b] : roads)
			print (a, b);
	}
	return 0;
}