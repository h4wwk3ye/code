//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 07:36:05 PM
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
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, q;
	cin >> n >> q;
	set< int > lower, upper;
	set< pii > flag;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			if (upper.find (y) != upper.end ()) {
				upper.erase (y);
				if (flag.find ({y, y - 1}) != flag.end ()) {
					flag.erase ({y, y - 1});
				}
				if (flag.find ({y, y + 1}) != flag.end ()) {
					flag.erase ({y, y + 1});
				}
				if (flag.find ({y, y}) != flag.end ()) {
					flag.erase ({y, y});
				}
			} else {
				upper.insert (y);
				if (lower.find (y - 1) != lower.end ()) {
					flag.insert ({y, y - 1});
				}
				if (lower.find (y + 1) != lower.end ()) {
					flag.insert ({y, y + 1});
				}
				if (lower.find (y) != lower.end ()) {
					flag.insert ({y, y});
				}
			}
		} else {
			if (lower.find (y) != lower.end ()) {
				lower.erase (y);
				if (flag.find ({y - 1, y}) != flag.end ()) {
					flag.erase ({y - 1, y});
				}
				if (flag.find ({y + 1, y}) != flag.end ()) {
					flag.erase ({y + 1, y});
				}
				if (flag.find ({y, y}) != flag.end ()) {
					flag.erase ({y, y});
				}
			} else {
				lower.insert (y);
				if (upper.find (y - 1) != upper.end ()) {
					flag.insert ({y - 1, y});
				}
				if (upper.find (y + 1) != upper.end ()) {
					flag.insert ({y + 1, y});
				}
				if (upper.find (y) != upper.end ()) {
					flag.insert ({y, y});
				}
			}
		}
		pr (len (flag) ? "No" : "Yes");
	}
	return 0;
}