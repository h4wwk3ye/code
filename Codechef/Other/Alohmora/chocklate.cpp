//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/Mar/20 11:27:48 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on


signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;

		int ans = 0;
		map< int, int > mp;
		int height = 0, width = 0;
		mp[0] = 0;
		for (auto& i : s) {
			if (i == 'U') {
				height++;
				if (mp.find (width) != mp.end ())
					mp.erase (width);
				else {
					mp[width] = height;
				}
			} else if (i == 'D') {
				height--;
				if (mp.find (width) != mp.end ())
					mp.erase (width);
				else {
					mp[width] = height;
				}
			} else if (i == 'L') {
				width--;
				if (mp.find (width) == mp.end ()) {
					mp[width] = height;
				} else {
					ans += abs (mp[width] - height);
					mp.erase (width);
				}
			} else {
				width++;
				if (mp.find (width) == mp.end ()) {
					mp[width] = height;
				} else {
					ans += abs (mp[width] - height);
					mp.erase (width);
				}
			}
			// pr (mp, ans, height, width);
		}
		mp.clear ();
		int curr = 0;
		mp[0] = 0;
		for (auto& i : s) {
			if (i == 'R') {
				height++;
				if (mp.find (width) != mp.end ())
					mp.erase (width);
				else {
					mp[width] = height;
				}
			} else if (i == 'L') {
				height--;
				if (mp.find (width) != mp.end ())
					mp.erase (width);
				else {
					mp[width] = height;
				}
			} else if (i == 'D') {
				width--;
				if (mp.find (width) == mp.end ()) {
					mp[width] = height;
				} else {
					curr += abs (mp[width] - height);
					mp.erase (width);
				}
			} else {
				width++;
				if (mp.find (width) == mp.end ()) {
					mp[width] = height;
				} else {
					curr += abs (mp[width] - height);
					mp.erase (width);
				}
			}
			// pr (mp, ans, height, width);
		}
		pr (max (ans, curr));
	}
	return 0;
}