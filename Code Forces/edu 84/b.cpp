//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 23/Mar/20 08:41:26 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		ve< int > g[n + 1];

		fr (i, 1, n + 1) {
			int k;
			cin >> k;
			fr (j, 0, k) {
				int x;
				cin >> x;
				g[i].pb (x);
			}
		}

		set< int > s;
		fr (i, 1, n + 1) s.insert (i);
		fr (i, 1, n + 1) {
			bool f = 0;
			for (auto& j : g[i]) {
				if (s.find (j) == s.end ()) continue;
				s.erase (j);
				f = 1;
				break;
			}
			if (f) g[i].pb (-1);
		}
		if (!len (s)) {
			pr ("OPTIMAL");
			continue;
		}
		bool f = 0;
		fr (i, 1, n + 1) {
			if (len (g[i]) and g[i].back () == -1) continue;
			set< int > x;
			for (auto& j : g[i])
				x.insert (j);

			for (auto& j : s) {
				if (x.find (j) == x.end ()) {
					pr ("IMPROVE");
					pr (i, j);
					f = 1;
					break;
				}
			}
			if (f) break;
		}
	}
	return 0;
}