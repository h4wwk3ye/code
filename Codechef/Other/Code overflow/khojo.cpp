//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 02:17:27 PM
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
	set< int > s;
	int q;
	cin >> q;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			s.insert (x);
		} else if (t == 2) {
			if (s.find (x) == s.end ())
				pr ("No");
			else
				pr ("Yes");
		} else {
			auto it = s.upper_bound (x);
			if (it == s.end ()) {
				pr (-1);
			} else {
				pr (*it);
			}
		}
	}
	return 0;
}